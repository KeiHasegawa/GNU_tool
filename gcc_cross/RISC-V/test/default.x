SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .sdata : {}
	 .sbss  : {}

	 . = 0x1000;
	 stack = .;
}
