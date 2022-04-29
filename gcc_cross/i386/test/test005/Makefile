all:test.objdump

include ../Makefile.common

por.o:por.S

post.o:post.S

bios_data.o:bios_data.S

dih.o:dih.S

vec.o:vec.S

int17.o:int17.S

#cfun.o:cfun.c
#	i386-elf-gcc -g -o $@ $< -c -m16

cfun.o:cfun.S
	i386-elf-as -o $@ $<

int18.o:int18.S

int19.o:int19.S

int12.o:int12.S

int11.o:int11.S

int15.o:int15.S

OBJS = por.o post.o bios_data.o dih.o vec.o int17.o cfun.o int18.o int19.o \
int12.o int11.o int15.o

test.elf:$(OBJS) por.x
	i386-elf-ld -o $@ -T por.x

test.objdump:test.elf
	i386-elf-objdump -x -d -g -M data16 $< > $@

test.lof:test.log
