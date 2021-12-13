all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:hello.c
	msp430-elf-gcc -g -o $@ $< -lsim -Tmsp430-sim.ld \
	-Wl,-Map -Wl,$(basename $<).map

hello.lof:hello.log
