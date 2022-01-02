MEMORY {
  text   (rx)   : ORIGIN = 0, LENGTH = 0x20000
  data   (rw!x) : ORIGIN = 0x800060, LENGTH = 0x10000-0x60
}

SECTIONS {
	 .text : {
	       *(.text)
	       *(.init4)
	 }
	 .data : {
	 	 __data_start = .;  /* VMA */
		 *(.data)
		 *(.rodata)
		 __data_end = .;    /* VMA */
	 } > data AT> text

	 .bss ADDR(.data) + SIZEOF (.data) : AT (ADDR (.bss)) {
	      __bss_start = .;
	      *(.bss)
	      __bss_end = . ;
	 } > data
	 __data_load_start = LOADADDR(.data);                    /* LMA */
	 __data_load_end = __data_load_start + SIZEOF(.data);    /* LMA */
}
