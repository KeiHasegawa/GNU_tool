SECTIONS {
	 . = 0x100;
	 .text : {
	       *(.text)
	       *(.plt)
	 }
	 .rodata : {}
	 .data : {}
	 .bss : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x8000;
	 _stack = .;
}
