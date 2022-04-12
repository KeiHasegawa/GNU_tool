all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o ../use_vector.o ../vector.o ../handler.o
	sparc-elf-ld -o $@ ../use_vector.o ../vector.o ../handler.o $< -T ../use_vector.x

test.lof:test.log

