SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x4000;
	 .stack : {}
	 PROVIDE(stack = .);
}
