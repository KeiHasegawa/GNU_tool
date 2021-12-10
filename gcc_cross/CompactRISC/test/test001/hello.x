SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss : {}

	 . = 0x2000;
 	 _heap = .;
	 
	 . = 0xf000;
	 _stack = .;
}
