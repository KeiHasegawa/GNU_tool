SECTIONS {
	 . = 0x100;
	 .text : {}
	 .data : {}

	 . = 0x20000;
	 stack = .;
}
