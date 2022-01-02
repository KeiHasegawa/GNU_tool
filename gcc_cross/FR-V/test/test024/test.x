SECTIONS {
	 . = 0x100;
	 .text : {}
	 
	 .data : {
	       PROVIDE(gp = .);
	       *(.rodata)
	       *(.data)
	 }

	 . = 0x1000;
	 .stack : {}
	 PROVIDE(_stack = .);
}
