SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x1000;
	 .stack : {}
	 PROVIDE(_stack = .);
}
