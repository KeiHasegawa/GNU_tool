ENTRY(power_on_reset)

SECTIONS {

	. = 0xfff0;
	.por : { por.o(.text) }
}
