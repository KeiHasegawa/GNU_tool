SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x10000;
	 _heap = .;

	 . = 0x20000;
	 _stack = .;
}
