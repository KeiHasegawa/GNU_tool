SECTIONS {
	 . = 0x500;
	 .text : {}

	 . = 0x1000;
	 .stack : {}
	 PROVIDE(stack = .);
}
