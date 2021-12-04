SECTIONS {
	 . = 0x500;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;
	 
	 . = 0xff00;
	 _stack = .;
}
