SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0xf000;
	 _stack = .;
}
