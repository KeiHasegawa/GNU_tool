SECTIONS {
	 . = 0x0;
 	 __c6xabi_DSBT_BASE = .;
	 . = 0x100;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x20000;
	 stack = .;
}
