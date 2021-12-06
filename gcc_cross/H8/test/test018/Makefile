all:test018.objdump test018.lof

#test018.s:test018.cpp
#	h8300-elf-g++ -o $@ $< -S -I/usr/local/include/c++/10.2.0 -I/usr/local/include/c++/10.2.0/i686-pc-linux-gnu -I/usr/include

#test018.o:test018.s
#	h8300-elf-as -o $@ $< -g

test018.o:test018.cpp
	h8300-elf-g++ -o $@ $< -g -c -I/usr/local/include/c++/10.2.0 -I/usr/local/include/c++/10.2.0/i686-pc-linux-gnu -I/usr/include

#mine2.s:mine2.cpp
#	h8300-elf-g++ -o $@ $< -S

#mine2.o:mine2.s
#	h8300-elf-as -o $@ $< -g

mine2.o:mine2.cpp
	h8300-elf-g++ -o $@ $< -g -c

mine.o:mine.S
	h8300-elf-as -o $@ $< -g

test018.elf:test018.o mine.o mine2.o
	h8300-elf-ld -o $@ /home/khasegawa/lang/53_GNU_tool/gcc_cross/H8/tool/start.o test018.o mine.o mine2.o /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/h8300-elf/10.2.0/libgcc.a -T /home/khasegawa/lang/53_GNU_tool/gcc_cross/H8/tool/sample.x

test018.objdump:test018.elf
	h8300-elf-objdump -x -d $< > $@

test018.log:test018.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test018.lof:test018.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.objdump *.log *~
