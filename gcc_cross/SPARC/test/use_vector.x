SECTIONS {
	 . = 0x100;
	 .text : {}

	 . = 0x1000;
	 .vector : { ../vector.o(.text) }
	 
	 . = 0x2000;
	 stack = .;
}
