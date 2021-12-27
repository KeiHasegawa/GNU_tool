include ../Makefile.common

test.elf:test.o test.x
	arm-elf-ld -o $@ $< -T $(basename $<).x
