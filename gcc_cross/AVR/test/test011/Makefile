all:hello.elf hello.objdump hello.lof

LIBDIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/avr-elf/lib

hello.elf:start.o hello.o dummy.o
	avr-elf-ld -o hello.elf start.o hello.o dummy.o -L$(LIBDIR) -lc \
-Map hello.map -T hello.x

#%.s:%.c
#	avr-elf-gcc -S -o $@ $<
#
#%.o:%.s
#	avr-elf-as -g -o $@ $<
#
#hello.o:hello.s
#dummy.o:dummy.s

%.o:%.c
	avr-elf-gcc -g -c -o $@ $<

start.o:start.S
	avr-elf-as -g -o start.o start.S

hello.elf:Makefile

hello.objdump:hello.elf
	avr-elf-objdump -x -d hello.elf > hello.objdump

hello.log:hello.elf gdbcom
	wdog.exe -v avr-elf-gdb -q -x gdbcom $< > $@

hello.lof:hello.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s hello.elf hello.objdump *.map *.log *~

