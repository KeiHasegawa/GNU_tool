#if 0
void int17_function(pusha_regs_t regs, // regs pushed from PUSHA instruction
		    Bit16u ds, // previous DS:, DS set to 0x0000 by asm wrapper
		    iret_addr_t iret_addr) // CS,IP,Flags pushed from original INT call
{
  Bit16u addr,timeout;
  Bit8u val8;

  ASM_START
  sti
  ASM_END

  addr = read_word_DS(0x0400 + (regs.u.r16.dx << 1) + 8);
  if ((regs.u.r8.ah < 3) && (regs.u.r16.dx < 3) && (addr > 0)) {
    HIBYTE(timeout) = read_byte_DS(0x0478 + regs.u.r16.dx);
    LOBYTE(timeout) = 0;
    if (regs.u.r8.ah == 0) {
      outb(addr, regs.u.r8.al);
      val8 = inb(addr+2);
      outb(addr+2, val8 | 0x01); // send strobe
      ASM_START
      nop
      ASM_END
      outb(addr+2, val8 & ~0x01);
      while (((inb(addr+1) & 0x40) == 0x40) && (timeout)) {
        timeout--;
      }
    }
    if (regs.u.r8.ah == 1) {
      val8 = inb(addr+2);
      outb(addr+2, val8 & ~0x04); // send init
      ASM_START
      nop
      ASM_END
      outb(addr+2, val8 | 0x04);
    }
    val8 = inb(addr+1);
    regs.u.r8.ah = (val8 ^ 0x48);
    if (!timeout) regs.u.r8.ah |= 0x01;
    ClearCF(iret_addr.flags);
  } else {
    SetCF(iret_addr.flags); // Unsupported
  }
}
#else
void int17_function()
{
  asm("int3");
}
#endif

typedef unsigned short int uint16_t;

void int19_function(uint16_t seq_nr)
{
}
