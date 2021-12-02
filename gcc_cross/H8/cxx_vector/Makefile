all:use_vec.objdump

#use_vec.s:use_vec.cpp
#	h8300-elf-g++ -o $@ $< -S -I/usr/local/include/c++/10.2.0 -I/usr/local/include/c++/10.2.0/i686-pc-linux-gnu -I/usr/include

#use_vec.o:use_vec.s
#	h8300-elf-as -o $@ $< -g

use_vec.o:use_vec.cpp
	h8300-elf-g++ -o $@ $< -g -c -I/usr/local/include/c++/10.2.0 -I/usr/local/include/c++/10.2.0/i686-pc-linux-gnu -I/usr/include

#mine2.s:mine2.cpp
#	h8300-elf-g++ -o $@ $< -S

#mine2.o:mine2.s
#	h8300-elf-as -o $@ $< -g

mine2.o:mine2.cpp
	h8300-elf-g++ -o $@ $< -g -c

mine.o:mine.S
	h8300-elf-as -o $@ $< -g

use_vec.elf:use_vec.o mine.o mine2.o
	h8300-elf-ld -o $@ /home/khasegawa/lang/53_GNU_tool/gcc_cross/H8/tool/start.o use_vec.o mine.o mine2.o /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/h8300-elf/10.2.0/libgcc.a -T /home/khasegawa/lang/53_GNU_tool/gcc_cross/H8/tool/sample.x

use_vec.objdump:use_vec.elf
	h8300-elf-objdump -x -d $< > $@

clean:
	rm -f *.o *.s *.elf *.objdump *~
