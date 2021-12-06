all:test005.objdump test005.lof

start.o:start.S
	h8300-elf-as -o start.o -g start.S

test005.o:test005.c
	h8300-elf-gcc -o test005.o -c -g test005.c

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/h8300-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/h8300-elf/lib/libc.a

test005.elf:start.o test005.o test005.x
	h8300-elf-ld -o test005.elf start.o test005.o \
	$(LIBGCC) $(LIBC) -T test005.x -Map test005.map

test005.objdump:test005.elf
	h8300-elf-objdump -x -t -d test005.elf > test005.objdump

test005.log:test005.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test005.lof:test005.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~
