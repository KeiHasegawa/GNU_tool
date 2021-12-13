SECTIONS {
	 . = 0x500;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x2100;
 	 _heap = .;
	 
	 . = 0x7000;
	 _stack = .;
}
