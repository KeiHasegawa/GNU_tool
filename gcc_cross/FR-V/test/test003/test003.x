SECTIONS {
	 . = 0x100;
	 .text : {}

	 .rodata : {}
	 _gp = .;
	 .sdata : {}
	 .sbss : {
	       _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x1000;
	 _heap = .;

	 . = 0x20000;
	 _stack = .;
}
