SECTIONS {
	 . = 0x10;
	 .softregs : {}

	 . = 0x80;
	 .text : {}

	 . = 0xfff0;
	 stack = .;
}
