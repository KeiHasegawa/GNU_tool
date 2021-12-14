SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .sdata : {}
	 .sbss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x20000;
	 _stack = .;
}
