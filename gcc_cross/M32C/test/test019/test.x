SECTIONS {
	 . = 0x500;
	 .text : {}
	 .plt : {}
	 .rodata : {}
	 .data : {}
	 .bss : {}

	 . = 0x2000;
	 stack = .;
}
