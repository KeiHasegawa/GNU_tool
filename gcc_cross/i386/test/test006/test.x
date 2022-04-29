ENTRY(power_on_reset)

SECTIONS {
	 . = 0xf800;
	 .gdt : { gdt.o(.text) }
	 .data : {}
	 . = 0xfff0;
	 .por : { por.o(.text)}

	 . = 0x10000;
	 .text : { startup.o(.text) test.o(.text) }

	 . = 0x20000;
	 stack = .;
}
