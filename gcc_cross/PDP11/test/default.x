SECTIONS {
	 . = 0x0;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss  : {}

	 . = 0xfffe;
	 stack = .;
}
