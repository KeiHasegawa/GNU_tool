SECTIONS {
	 . = 0x100;
	 .text : {}
	 . = ALIGN(4);
	 .rodata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x20000;
	 stack = .;
}
