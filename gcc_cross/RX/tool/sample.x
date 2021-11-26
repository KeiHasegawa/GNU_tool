SECTIONS {
	 . = 0x1000;
	 .text : {}

	 .= 0xf000;
	 .stack : {}
	 PROVIDE(_stack = .);
}
