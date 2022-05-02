ENTRY(power_on_reset)

SECTIONS {
	. = 0xfe00;
	.text : { ../default.o(.text) }
	.data : { ../default.o(.data) }
	. = 0xfff0;
	.por : { por.o(.text) }

	. = 0x10000;
	.text32 : { test.o(.text) }

	. = 0x20000;
	stack = .;
}
