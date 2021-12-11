SECTIONS {
	 . = 0x80000100;
	 .text : {}

	 . = 0x80001000;
	 .stack : {}
	 PROVIDE(stack = .);
}
