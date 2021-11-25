SECTIONS {
	 . = 0x10;
	 .softregs : {}

	 . = 0x0500;
	 .heap : {}
 	 PROVIDE(heap = .);

	 . = 0x1040;
	 .text : {}

	 . = 0x7000;
	 .stack : {}
	 PROVIDE(stack = .);	 
}
