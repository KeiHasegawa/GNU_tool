OUTPUT_ARCH(h8300:h8300h)
SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x1000;
	 .stack : {}
	 PROVIDE(stack = .);
}
