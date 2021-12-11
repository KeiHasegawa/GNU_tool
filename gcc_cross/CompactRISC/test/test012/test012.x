SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x1000;
	 PROVIDE(_heap = .);
	 . = 0x1500;
	 .stack : {}
	 PROVIDE(stack = .);
}
