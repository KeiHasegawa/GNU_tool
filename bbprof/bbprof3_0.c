#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <bfd.h>
#include "libbfd.h"
#include "elf-bfd.h"
#include "my_dwarf2.h"

extern int
_bfd_dwarf2_find_nearest_line2 (bfd *abfd,
			       asymbol **symbols,
			       asymbol *symbol,
			       asection *section,
			       bfd_vma offset,
			       struct line_sequence** seq,
			       int* index,
			       const char** func,
			       const struct dwarf_debug_section *debug_sections,
			       void **pinfo);

bfd_boolean
coff_find_nearest_line2 (bfd *abfd,
			asymbol **symbols,
			asection *section,
			bfd_vma offset,
			struct line_sequence** seq,
			int* index,
			const char **func);

bfd_boolean my_func(bfd *abfd,
		    asymbol **symbols,
		    asection *section,
		    bfd_vma offset,
		    struct line_sequence** seq,
		    int* index,
		    const char **func)
{
#ifdef linux  
  if (_bfd_dwarf2_find_nearest_line2 (abfd, symbols, NULL, section, offset,
				      seq, index, func,
				      dwarf_debug_sections,
			      &elf_tdata (abfd)->dwarf2_find_line_info))
    return TRUE;
  return FALSE;
#endif // linux
#ifdef __CYGWIN__
  return coff_find_nearest_line2 (abfd, symbols, section, offset,
				  seq, index, func);
#endif //  __CYGWIN__
}
