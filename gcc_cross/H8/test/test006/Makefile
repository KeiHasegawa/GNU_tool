all:test006.objdump test006.lof

start.o:start.S
	h8300-elf-as -o start.o -g start.S

#test006.s:test006.c
#	h8300-elf-gcc -o test006.s -g -S test006.c

#test006.o:test006.s
#	h8300-elf-as -o test006.o test006.s

test006.o:test006.c
	h8300-elf-gcc -o $@ $< -c -g

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/h8300-elf/lib/libc.a

test006.elf:start.o test006.o test006.x
	h8300-elf-ld -o test006.elf start.o test006.o \
	$(LIBC) -T test006.x -Map test006.map

test006.objdump:test006.elf
	h8300-elf-objdump -x -t -d -g test006.elf > test006.objdump

test006.log:test006.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test006.lof:test006.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~


