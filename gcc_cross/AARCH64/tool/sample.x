SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0xf000;
	 .stack : {}
	 PROVIDE(_stack = .);	
}
