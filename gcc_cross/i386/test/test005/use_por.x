ENTRY(power_on_reset)
SECTIONS {
	 . = 0x100;
	 .text : {}
	 
	 . = 0xfff0;
	 .por : {../power_on_reset.o(.text)}
}
