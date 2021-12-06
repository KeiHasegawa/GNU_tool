all:test008.objdump test008.lof

start.o:start.S
	h8300-elf-as -o start.o -g start.S

#test008.s:test008.c
#	h8300-elf-gcc -o test008.s -g -S test008.c -mh

#test008.o:test008.s
#	h8300-elf-as -o test008.o test008.s

test008.o:test008.c
	h8300-elf-gcc -o $@ $< -c -g -mh

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/h8300-elf/lib/h8300h/libc.a

test008.elf:start.o test008.o test008.x
	h8300-elf-ld -o test008.elf start.o test008.o \
	$(LIBC) -T test008.x -Map test008.map

test008.objdump:test008.elf
	h8300-elf-objdump -x -t -d -g test008.elf > test008.objdump

test008.log:test008.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test008.lof:test008.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~
