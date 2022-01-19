all:test.objdump test.lof

include ../Makefile.common

test.o:test.cpp
	h8300-elf-g++ -o $@ $< -g -c -I/usr/local/include/c++/10.2.0 -I/usr/local/include/c++/10.2.0/i686-pc-linux-gnu -I/usr/include

mine2.o:mine2.cpp
	h8300-elf-g++ -o $@ $< -g -c

START_O = /home/khasegawa/lang/53_GNU_tool/gcc_cross/H8/tool/start.o
LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/h8300-elf/10.2.0/libgcc.a
SAMPLE_X = /home/khasegawa/lang/53_GNU_tool/gcc_cross/H8/tool/sample.x

test.elf:test.o mine.o mine2.o
	h8300-elf-ld -o $@ $(START_O) $< mine.o mine2.o $(LIBGCC) -T $(SAMPLE_X)

test.lof:test.log
