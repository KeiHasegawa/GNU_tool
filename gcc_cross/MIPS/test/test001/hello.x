SECTIONS {
	 . = 0xa0020000;
	 .text : {}
	 .rdata : {}
	 _gp = . ;
	 .sdata : {}
	 .sbss : {
	       _bss_start = .;
	 }
	 .bss : {}
	 _bss_end = .;

	 . = 0xa0024000;
	 _end = .;

	 . = 0xa0026000;
	 _stack = .;
}
