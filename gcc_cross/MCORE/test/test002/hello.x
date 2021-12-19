SECTIONS {
	 . = 0x100;
	 .text : {}
	 .romdata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x3b00;
	 heap = .;

	 . = 0x5b00;
	 stack = .;
}
