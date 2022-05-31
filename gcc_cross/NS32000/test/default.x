SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss  : {}

	 . = 0x1000;
	 _stack = .;
}
