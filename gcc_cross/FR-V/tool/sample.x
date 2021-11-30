SECTIONS {
	 . = 0x100;
	 .text : {}

	 .rodata : {}
	 _gp = .;
	 .sdata : {}
	 .sbss : {}

	 . = 0xf000;
	 .stack : {}
	 PROVIDE(_stack = .);
}
