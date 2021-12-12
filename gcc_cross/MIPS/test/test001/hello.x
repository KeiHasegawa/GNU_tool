SECTIONS {
	 . = 0xa0020000;
	 .text : {}

	 . = ALIGN(8);
	 _gp = . ;
	 .sdata : {}

	 . = 0xa0024000;
	 _end = .;

	 . = 0xa0026000;
	 _stack = .;
}
