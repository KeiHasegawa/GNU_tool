all:hello.objdump hello.lof

include ../Makefile.common

hello.elf:start.o hello.o hello.x Makefile
	mips-elf-ld -o $@ start.o hello.o -T hello.x \
/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/mips-elf/lib/libc.a \
/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/mips-elf/lib/libidt.a

hello.lof:hello.log



