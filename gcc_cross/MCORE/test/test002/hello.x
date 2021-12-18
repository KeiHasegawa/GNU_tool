SECTIONS {
	 . = 0x100;
	 .text : {}
	 .romdata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x3000;
	 heap = .;

	 . = 0x5000;
	 stack = .;
}
