SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss : {}

	 . = 0x20000;
	 PROVIDE(_stack = .);	
}
