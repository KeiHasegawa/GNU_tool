ENTRY(power_on_reset)

SECTIONS {
	. = 0x0;
	.vec : { vec.o(.bss) }

	. = 0x0400;
	.bios_data : { bios_data.o(.bss) }

	. = 0xe6f2;
	.int19 : { int19.o(.text) }
	
	. = 0xefd2;
	.int17 : { int17.o(.text) }

	. = 0xe05b;
	.post : { post.o(.text) cfun.o(.text) int18.o(.text) }

	. = 0xf841;
	.int12 : { int12.o(.text) }

	. = 0xf84d;
	.int11 : { int11.o(.text) }

	. = 0xf859;
	.int15 : { int15.o(.text) }

	. = 0xff53;
	.dih : { dih.o(.text) }

	. = 0xfff0;
	.por : { por.o(.text) }

	. = 0x0;  /* 0x10000 */
	stack = .;
	 
	PORT_DMA1_MASTER_CLEAR	= 0x000d;
	PORT_DMA2_MASTER_CLEAR	= 0x00da;
	PORT_DMA2_MODE_REG	= 0x00d6;
	PORT_DMA2_MASK_REG	= 0x00d4;
	PORT_CMOS_INDEX		= 0x0070;
	PORT_CMOS_DATA		= 0x0071;
	PORT_PIC1_CMD		= 0x0020;
	PORT_PIC2_CMD		= 0x00a0;
}
