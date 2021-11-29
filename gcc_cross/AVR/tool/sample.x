SECTIONS {
	 . = 0x100;
	 .text : {
	       *(.text)	 
	       *(.init4)	 
	 }
	 PROVIDE(_etext = .);
	 .data : {
	 	 PROVIDE (__data_start = .) ;
		 *(.data)
		 *(.rodata)
		 PROVIDE (__data_end = .) ;		 
	 }
         __data_load_start = LOADADDR (.data);
         __data_load_end = (__data_load_start + SIZEOF (.data));
	 .bss : {
	 	 PROVIDE (__bss_start = .) ;
		 *(.bss)
		 PROVIDE (__bss_end = .) ;		 
	 }
}
