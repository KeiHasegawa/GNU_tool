SECTIONS {
	 . = 0x100;
	 .text : {}

	 .rodata : {}
	 .sdata : {}
	 _gp = .;	 
	 .sbss : {
	       _sbss_start = .;
	 }
	 _sbss_end = .;

	 .data : {}
	 .bss : {
	       _bss_start = .;
	 }
	 _bss_end = .;
	 
	 . = 0x6000;
	 _heap = .;

	 . = 0x20000;
	 _stack = .;
}
