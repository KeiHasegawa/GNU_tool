all:hello.objdump hello.lof

include ../Makefile.common

PREFIX = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG

LIBGCC = $(PREFIX)/lib/gcc/ft32-elf/10.2.0/libgcc.a

LIBC = $(PREFIX)/ft32-elf/lib/libc.a

LIBSIM = $(PREFIX)/ft32-elf/lib/libsim.a

LIBG = $(PREFIX)/ft32-elf/lib/libg.a

hello.elf:start.o hello.o hello.x
	ft32-elf-ld -o $@ start.o hello.o \
	$(LIBGCC) $(LIBC) $(LIBSIM) $(LIBG) -T hello.x -Map hello.map

hello.lof:hello.log
