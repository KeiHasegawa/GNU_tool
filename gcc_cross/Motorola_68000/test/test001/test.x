SECTIONS {
	 . = 0x10;
	 .softregs : {}
	 
	 .text : {}
	 . = 0x80;

	 . = 0xfff0;
	 stack = .;
	 
}
