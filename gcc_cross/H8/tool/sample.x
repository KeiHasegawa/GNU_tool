SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0xe000;
	 .stack : {}
	 PROVIDE(stack = .);
}
