SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 _bss_start = .;
	 .bss : {}
	 _bss_end = .;

	 . = 0x20000;
	_stack = .;
}
