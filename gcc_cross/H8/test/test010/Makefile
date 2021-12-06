all:test010.objdump test010.lof

start.o:start.S
	h8300-elf-as -o start.o -g start.S

#test010.s:test010.c
#	h8300-elf-gcc -o test010.s -g -S test010.c -mh

#test010.o:test010.s
#	h8300-elf-as -o test010.o test010.s

test010.o:test010.c
	h8300-elf-gcc -o $@ -g -c $< -mh


LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/h8300-elf/lib/h8300h/libc.a

test010.elf:start.o test010.o test010.x
	h8300-elf-ld -o test010.elf start.o test010.o \
	$(LIBC) -T test010.x -Map test010.map

test010.objdump:test010.elf
	h8300-elf-objdump -x -t -d -g test010.elf > test010.objdump

test010.log:test010.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test010.lof:test010.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~
