all:test.objdump test.lof

include ../Makefile.common

por.o:por.S

post.o:post.S

test.elf:por.o post.o por.x
	i386-elf-ld -o $@ -T por.x

test.objdump:test.elf

test.lof:test.log
