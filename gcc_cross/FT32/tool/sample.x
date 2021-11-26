SECTIONS {
	 . = 0x100;
	 .text : {}
	 . = ALIGN(4);
	 PROVIDE(data_start = .);
	 .data : {}
	 .rodata : {}
	 . = ALIGN(4);	 
	 PROVIDE(data_end = .);
	 .bss : {}

	 . = 0xf000;
	 .stack : {}
	 PROVIDE(stack = .);
}

