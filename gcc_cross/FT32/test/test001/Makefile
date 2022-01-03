all:
	wdog.exe -v diff hello.log hello.lof

#all:hello.objdump hello.log

include ../Makefile.common

DIR0 = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG
DIR1 = $(DIR0)/ft32-elf/lib
DIR2 = $(DIR0)/lib/gcc/ft32-elf/10.2.0

CRT0 = $(DIR1)/crt0.o

LIBGCC = -L$(DIR2) -lgcc

LIBC = -L$(DIR1) -lc

LIBSIM = -L$(DIR1) -lsim

hello.elf:hello.o
	ft32-elf-ld -o $@ $(CRT0) hello.o $(LIBGCC) $(LIBC) -T sim.ld

hello.lof:hello.log
