SECTIONS {
	 . = 0xa0020000;
	 .text : {}

	 . = ALIGN(8);
	 _gp = . ;
	 .sdata : {}

	 . = 0xa0021000;
	 .heap : {}
	 PROVIDE(_end = .);

	 . = 0xa0022000;
	 .stack : {}
	 PROVIDE(stack = .);
}
