#include "config.h"
#include "bfd.h"
#include <cstring>
#include "elf-bfd.h"
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

struct deleted_info {
  bfd_section* section;
  bfd_vma addr;
  int count;
  int org;
  int count2;
};

std::vector<deleted_info> deleted;

inline int org_len(bfd_byte* contents, bfd_vma addr)
{
  auto b1 = contents[addr-1];
  switch (b1) {
  case 0x05:     // movd : 6 bytes -> 4 bytes
  case 0x04:     // addd : 6 bytes -> 4 bytes
  case 0x56:     // cmpd : 6 bytes -> 4 bytes
  case 0x18:     // beq, bne, blt, ble, bgt, bge, br : 6 bytes -> 4 bytes
    return 6;
  default:
    assert(b1 == 0x10);
    // beq, bne, blt, ble, bgt, bge, br : 4 bytes -> 2 bytes
    return 4;
  }
}

inline bool comp(const deleted_info& info, bfd_section* section, bfd_vma addr)
{
  return info.section == section && info.addr == addr;
}

extern "C" void record_delete(bfd_section* section, bfd_vma addr, int count)
{
  auto contents = elf_section_data(section)->this_hdr.contents;
  auto org = org_len(contents, addr);
  auto p = find_if(begin(deleted), end(deleted),
		   [section, addr](const deleted_info& info)
		   { return comp(info, section, addr); });
  if (p == end(deleted)) {
    deleted.push_back(deleted_info{section, addr, count, org, 0});
    return;
  }
  p->count += count;
  p->count2 = count;
}

inline bool match(const deleted_info& info, bfd* abfd, int addr, int amount)
{
  auto section = info.section;
  auto owner = section->owner;
  if (owner != abfd)
    return false;
  int inst_end = info.addr + 2 * (info.count - info.count2);
  int inst_start = inst_end - info.org;
  if (inst_start == addr)
    return true;
  return addr < inst_start && inst_start < addr + amount;
}

inline int should_shrink(bfd* abfd, int addr, int amount)
{
  auto p = find_if(begin(deleted), end(deleted),
		   [abfd, addr, amount](const deleted_info& info)
		   { return match(info, abfd, addr, amount); });
  if (p == end(deleted))
    return 0;
  int ret = p->count;
  deleted.erase(p);
  return ret;
}

inline bfd_byte*
read_debug_line(bfd* abfd, bfd_byte* p, int opc_base, int* addr)
{
  auto code = *p++;
  switch (code) {
  case 1: return p;    // Opcode 1 has 0 args
  case 2: return p+1;  // Opcode 2 has 1 arg
  case 3:              // Opcode 3 has 1 arg
    {
      /* Advance Line by */
      auto line = bfd_get_8(abfd, p); p += 1;
      (void)line;
      return p;
    }
  case 4: return p+1;  // Opcode 4 has 1 arg
  case 5:              // Opcode 5 has 1 arg
    {
      /* Set column to */
      auto column = bfd_get_8(abfd, p); p += 1;
      (void)column;
      return p;
    }
  case 6: return p; // Opcode 6 has 0 args
  case 7: return p; // Opcode 7 has 0 args
  case 8: return p; // Opcode 8 has 0 args
  case 9:           // Opcode 9 has 1 arg
    {
      /* Advance PC by fixed size amount */
      auto amount = bfd_get_8(abfd,p);
      if (int delta = should_shrink(abfd, *addr, amount)) {
	amount -= delta;
	*p = amount;
      }
      p += 1;
      *addr += amount;
      return p;
    }
  case 10: return p;   // Opcode 10 has 0 args
  case 11: return p;   // Opcode 11 has 0 args
  case 12: return p+1; // Opcode 12 has 1 arg
  case 0:
    {
      /* Extended opcode */
      auto narg = *p++;
      auto opc = *p++;
      switch(opc) {
      case 1:
	{
	  /* End of column */
	  assert(narg == 0);
	  return p;
	}
      case 2:
	{      
	  /* Set address */
	  auto tmp = bfd_get_32(abfd, p);
	  p += narg;
	  *addr = tmp;
	  return p;
	}
      case 3:
	{
	  /* Copy view `x' */
	  assert(narg == 1);
	  auto x = bfd_get_8(abfd, p); p += 1;
	  (void)x;
	  return p;
	}
      default:
	{
	  p += narg;
	  return p;
	}
      }
    }
  default:
    {
      int x = code - opc_base;
      // Special opcode `x': advance Address by 0 to 0x0 and Line by `y' to 'z'
      // where, `y' is equal to `x' - 1
      (void)x;
      return p;
    }
  }
}

extern "C" void modify_deleted(bfd* abfd, bfd_byte* buf)
{
  using namespace std;
  auto start = buf;
  (void)start;
  auto length = bfd_get_32(abfd, buf); buf += 4;
  auto end = start + length;
  auto ver = bfd_get_16(abfd, buf); buf += 2;
  (void)ver;
  auto prologue = bfd_get_32(abfd, buf); buf += 4;
  (void)prologue;
  auto line_stmt = buf + prologue;
  auto minimum = bfd_get_8(abfd, buf); buf += 1;
  (void)minimum;
  auto is_stmt = bfd_get_8(abfd, buf); buf += 1;
  (void)is_stmt;
  auto line_base = (int)(char)bfd_get_8(abfd, buf); buf += 1;
  (void)line_base;  
  auto line_range = bfd_get_8(abfd, buf); buf += 1;
  (void)line_range;
  auto opc_base = bfd_get_8(abfd, buf); buf += 1;
  int narg[20];
  assert(opc_base < sizeof narg/sizeof narg[0]);  
  for (int i = 0 ; i != int(opc_base-1) ; ++i) {
    narg[i] = bfd_get_8(abfd, buf); buf += 1;
  }
  (void)narg;
  char* dir = 0;
  for ( ; bfd_get_8(abfd, buf) ; ++buf) {
    dir = (char*)buf;
    while(*buf++)
      ;
    (void)dir;
  }
  if (dir) {
    while (!*++buf)
      ;
  }
  else
    ++buf;
  char* fn = (char*)buf; while(*buf++);
  (void)fn;
  while (buf < line_stmt) {
    while (!*++buf)
      ;
    if (buf >= line_stmt)
      break;
    char* other = (char*)buf;
    while(*buf++)
      ;
    (void)other;
  }
  int addr = 0xbadbeef;
  while (line_stmt < end)
    line_stmt = read_debug_line(abfd, line_stmt, opc_base, &addr);
}

struct check {
  ~check()
  {
    assert(deleted.empty());
  }
} check;

void debug(const deleted_info& info)
{
  using namespace std;
  auto sec = info.section;
  auto owner = sec->owner;
  cerr << owner->filename << ' ';
  cerr << hex << "0x" << info.addr << ' ';
  cerr << dec << info.count << ' ' ;
  cerr << dec << info.org << ' ' << info.count2 << '\n'; 
}

void debug()
{
  for (const auto& x : deleted)
    debug(x);
}
