SECTIONS {
	 . = 0xa0020000;
	 .text : {}
	 .rdata : {}
	 _gp = . ;
	 .sdata : {}
	 .sbss : {
	       _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0xa0040000;
	 _stack = .;


}
