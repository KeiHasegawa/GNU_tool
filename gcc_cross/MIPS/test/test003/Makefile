all:test003.objdump test003.log

include ../Makefile.common

test003.elf:start.o test003.o test003.x
	mips-elf-ld -o $@ start.o test003.o -T test003.x \
/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/mips-elf/lib/libc.a \
/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/mips-elf/10.2.0/libgcc.a \


test003.lof:test003.log


#--defsym _exit=0xa0020000
