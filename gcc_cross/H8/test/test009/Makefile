all:test009.objdump test009.lof

start.o:start.S
	h8300-elf-as -o start.o -g start.S

test009.s:test009.c
	h8300-elf-gcc -o test009.s -g -S test009.c -mh

test009.o:test009.s
	h8300-elf-as -o test009.o test009.s

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/h8300-elf/lib/h8300h/libc.a

test009.elf:start.o test009.o test009.x
	h8300-elf-ld -o test009.elf start.o test009.o \
	$(LIBC) -T test009.x -Map test009.map

test009.objdump:test009.elf
	h8300-elf-objdump -x -t -d -g test009.elf > test009.objdump

test009.log:test009.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test009.lof:test009.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *~
