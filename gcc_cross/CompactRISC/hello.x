SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x2000;
 	 PROVIDE(_heap = .);
	 
	 . = 0x3000;
	 .stack : {}
	 PROVIDE(stack = .);
}
