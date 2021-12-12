SECTIONS {
	 . = 0xa0020000;
	 .text : {}

	 . = ALIGN(8);
	 _gp = . ;
	 .sdata : {}

	 . = 0xa0021000;
	 .stack : {}
	 PROVIDE(stack = .);


}
