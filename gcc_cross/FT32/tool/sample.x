SECTIONS {
	 . = 0x100;
	 .text : {}
	 
	 .data : {
	 	 _data_start = .;
	 }
 	 _data_end = .;
	 
	 .rodata : {
	 	 _rodata_start = .;
	 }
	 _rodata_end = .;

	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0xf000;
	 stack = .;
}

