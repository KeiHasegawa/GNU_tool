all:test.objdump

include ../Makefile.common

por.o:por.S

post.o:post.S

post32.o:post32.S

bios_data.o:bios_data.S

dih.o:dih.S

vec.o:vec.S

test.elf:por.o post.o post32.o bios_data.o dih.o vec.o por.x
	i386-elf-ld -o $@ -T por.x

test.objdump:test.elf

test.lof:test.log
