SECTIONS {
	 . = 0x80000100;
	 .text : {}

	 . = 0x8000f000;
	 .stack : {}
	 PROVIDE(stack = .);
}
