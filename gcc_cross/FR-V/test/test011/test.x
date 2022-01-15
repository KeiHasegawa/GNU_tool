SECTIONS {
	 . = 0x100;
	 .text : {}

	 .rodata : {}
	 _gp = .;
	 .sdata : {}
	 .sbss : {
	       _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0xf000;
	 .stack : {}
	 PROVIDE(_stack = .);
}
