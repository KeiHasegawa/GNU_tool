SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x4000;
	 PROVIDE(_heap = .);

	 . = 0x6000;
	 .stack : {}
	 PROVIDE(stack = .);	
}
