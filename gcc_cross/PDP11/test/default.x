SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss  : {}

	 . = 0xffc0;
	 stack = .;
}
