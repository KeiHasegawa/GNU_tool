SECTIONS {
	 . = 0x500;
	 .text : {}

	 . = 0x2500;
 	 PROVIDE(_heap = .);
	 
	 . = 0x3000;
	 .stack : {}
	 PROVIDE(stack = .);
}
