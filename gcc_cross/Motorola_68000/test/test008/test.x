SECTIONS {
	 . = 0x10;
	 .softregs : {}

	 . = 0x0500;
	 .heap : {}
 	 PROVIDE(heap = .);
	 . = 0x1000;
	 .stack : {}
	 PROVIDE(stack = .);	 

	 . = 0x1040;
	 .text : {}
}
