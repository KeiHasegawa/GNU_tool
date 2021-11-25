SECTIONS {
	 . = 0x500;
	 .text : {}

	 . = 0x7000;
	 .stack : {}
	 PROVIDE(stack = .);
}
