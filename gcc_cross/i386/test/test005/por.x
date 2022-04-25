ENTRY(power_on_reset)

SECTIONS {
	. = 0xe0b5;
	.post : { post.o(.text) }

	. = 0xfff0;
	.por : { por.o(.text) }
	 
	PORT_DMA1_MASTER_CLEAR	= 0x000d;
	PORT_DMA2_MASTER_CLEAR	= 0x00da;
	PORT_DMA2_MODE_REG	= 0x00d6;
	PORT_DMA2_MASK_REG	= 0x00d4;
	PORT_CMOS_INDEX		= 0x0070;
	PORT_CMOS_DATA		= 0x0071;
}
