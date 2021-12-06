all:test007.objdump test007.lof

start.o:start.S
	h8300-elf-as -o start.o -g start.S

#test007.s:test007.c
#	h8300-elf-gcc -o test007.s -g -S test007.c -mh

#test007.o:test007.s
#	h8300-elf-as -o test007.o test007.s

test007.o:test007.c
	h8300-elf-gcc -o $@ $< -c -g -mh

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/h8300-elf/lib/h8300h/libc.a

test007.elf:start.o test007.o test007.x
	h8300-elf-ld -o test007.elf start.o test007.o \
	$(LIBC) -T test007.x -Map test007.map

test007.objdump:test007.elf
	h8300-elf-objdump -x -t -d -g test007.elf > test007.objdump

test007.log:test007.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test007.lof:test007.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~
