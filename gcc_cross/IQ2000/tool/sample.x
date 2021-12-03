SECTIONS {
	 . = 0x00000100;
	 .data : {}
	 .rodata : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;
	 
	 . = 0x80000100;
	 .text : {}
	 
	 . = 0x80020000;
	 _stack = .;
}
