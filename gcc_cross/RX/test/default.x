SECTIONS {
	 . = 0x1000;
	 .text : {}

	 .= 0x2000;
	 .stack : {}
	 PROVIDE(_stack = .);
}
