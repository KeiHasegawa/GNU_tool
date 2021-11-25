SECTIONS {
	 . = 0x80000100;
	 .text : {}

	 . = 0x80006000;
	 .stack : {}
	 PROVIDE(stack = .);
}
