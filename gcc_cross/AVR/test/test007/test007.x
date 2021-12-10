SECTIONS {
	 . = 0x100;
	 .text : {}
	 PROVIDE(_etext = .);
	 .data : {
	 	 PROVIDE (__data_start = .) ;
		 *(.data)
		 *(.rodata)
		 PROVIDE (__data_end = .) ;		 
	 }
         __data_load_start = LOADADDR (.data);
         __data_load_end = (__data_load_start + SIZEOF (.data));


	 . = 0x1000;
	 .stack : {}
	 PROVIDE(stack = .);
}
