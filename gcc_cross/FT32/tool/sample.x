MEMORY {
       flash     (rx)   : ORIGIN = 0,        LENGTH = 0x40000
       ram       (rw!x) : ORIGIN = 0x800000, LENGTH = 0x10000
}

SECTIONS {
	 .text : {} > flash
	 
	 .data : {
	       _data_start = .;  /* VMA */
	       *(.data)
	       *(.rodata)
	       *(.rodata*)
	       _data_end = .;    /* VMA */
	 } > ram AT> flash
	 
	 .bss ADDR(.data) + SIZEOF(.data) : {
	      _bss_start = .;
	      *(.bss)
	      _bss_end = .;	      
	 } > ram
	 __data_load_start = LOADADDR(.data);                    /* LMA */
	 __data_load_end = __data_load_start + SIZEOF(.data);    /* LMA */

	 . = 0xf000;
	 stack = .;
}

