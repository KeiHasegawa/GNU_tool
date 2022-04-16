SECTIONS {
	 . = 0x100;
	 .text : {}
	 text_end = .;

	 . = 0x1000;
	 stack = .;
}
