SECTIONS {
	 . = 0x100;
	 .text : {}
	 _data_start = .;
	 .data : {}
	 .rodata : {}
	 _data_end = .;
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0xf000;
	 stack = .;
}

