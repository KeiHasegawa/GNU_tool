SECTIONS {
	 . = 0x1000;
	 .text : {}

	 .= 0x3000;
	 .stack : {}
	 PROVIDE(_stack = .);
}
