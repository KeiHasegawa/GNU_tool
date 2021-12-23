SECTIONS {
	 . = 0x1000;
	 P : {}
	 C : {}
	 D : {}
	 B : {
	      _bss_start = .;
	 }
	 _bss_end = .;

	 . = 0x20000;
	 _stack = .;
}
