SECTIONS {
	 . = 0x100;
	 .text : {}
	 .rodata : {
	 	 __c6xabi_DSBT_BASE = .;
	 }
	 .data : {}
	 .bss  : {}

	 . = 0x1000;
	 stack = .;
}
