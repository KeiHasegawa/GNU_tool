SECTIONS {
	 . = 0x100;
	 .text : {}
	 . = ALIGN(4);
	 PROVIDE(data_start = .);
	 .data : {}
	 .rodata : { *(.rodata) *(.rodata*) }
	 . = ALIGN(4);	 
	 PROVIDE(data_end = .);
	 .bss : {}
	 PROVIDE(_end = .);

	 . = 0x6000;
	 .stack : {}
	 PROVIDE(stack = .);
}

