SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .sdata : {
	        __SDATA_BEGIN__ = .;
	 }
	 .sbss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x20000;
	 stack = .;
}
