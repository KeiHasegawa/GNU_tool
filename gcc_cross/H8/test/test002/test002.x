SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x500;
	 .stack : {}
	 PROVIDE(stack = .);
}
