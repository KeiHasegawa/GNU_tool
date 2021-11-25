SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x6000;
	 .stack : {}
	 PROVIDE(_stack = .);
}
