SECTIONS {
	 . = 0x100;
	 .got : {}
	 .text : {}
	 .rodata : {}
	 .sdata : {}
	 .sbss  : {}

	 . = 0x1000;
	 stack = .;
}
