all:por.objdump por.lof

include ../Makefile.common

test.o:test.S

por.o:por.S

OBJS = por.o test.o

por.elf:$(OBJS)
	i386-elf-ld -o $@ $(OBJS) -T por.x

por.objdump:por.elf

por.lof:por.log
