ENTRY(power_on_reset)

SECTIONS {
	. = 0x0;
	.vec : { vec.o(.bss) }
	
	. = 0x0400;
	.bios_data : { bios_data.o(.bss) }
	
	. = 0xe0b5;
	.post : { post.o(.text) }

	. = 0xff53;
	.dih : { dih.o(.text) }

	. = 0xfff0;
	.por : { por.o(.text) }

	. = 0xfffe;
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
