SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x5000;
	 PROVIDE(end = .);
	 . = 0x6000;
	 .stack : {}
	 PROVIDE(stack = .);
}
