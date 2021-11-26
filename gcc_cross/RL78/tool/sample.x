SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x8000;
	 .stack : {}
	 PROVIDE(stack = .);
}
