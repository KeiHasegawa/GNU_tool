SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x3000;
	 .stack : {}
	 PROVIDE(stack = .);
}
