SECTIONS {
	 . = 0x00000100;
	 .data : {}
	 .rodata : {}
	 
	 . = 0x80000100;
	 .text : {}
	 
	 . = 0x8000f000;
	 PROVIDE(stack = .);
}
