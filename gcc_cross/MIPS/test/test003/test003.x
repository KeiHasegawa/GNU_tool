SECTIONS {
	 . = 0xa0020000;
	 .text : {}

	 . = ALIGN(8);
	 _gp = . ;
	 .sdata : {}
	 .bss : {}

	 . = 0xa0021000;
	 _end = .;

	 . = 0xa0022000;
	 _stack = .;
}
