SECTIONS {
	 . = 0x10;
	 .softregs : {}

	 . = 0x1040;
	 .text : {}
	 .rodata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0xff00;
	 _stack = .;
}
