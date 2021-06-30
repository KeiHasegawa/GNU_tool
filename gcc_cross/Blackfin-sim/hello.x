SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x3000;
	 PROVIDE(_end = .);

	 . = 0x4000;
	 .stack : {}
	 PROVIDE(stack = .);
}
