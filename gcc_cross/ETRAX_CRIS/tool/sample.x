SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x2000;
	 .stack : {}
	 PROVIDE(_stack = .);
}
