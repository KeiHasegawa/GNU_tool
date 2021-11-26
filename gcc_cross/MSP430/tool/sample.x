SECTIONS {
	 . = 0x500;
	 .text : {}

	 . = 0xff00;
	 .stack : {}
	 PROVIDE(stack = .);
}
