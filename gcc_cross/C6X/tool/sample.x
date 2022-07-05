SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {
	 	 __c6xabi_DSBT_BASE = .;
	 }
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x20000;
	 stack = .;
}
