all:test002.objdump test002.lof

start.o:start.S
	h8300-elf-as -o start.o -g start.S

#test002.s:test002.c
#	h8300-elf-gcc -o test002.s -S test002.c

#test002.o:test002.s
#	h8300-elf-as -o test002.o -g test002.s

test002.o:test002.c
	h8300-elf-gcc -o test002.o -g -c test002.c

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/h8300-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/h8300-elf/lib/libc.a

test002.elf:start.o test002.o test002.x
	h8300-elf-ld -o test002.elf start.o test002.o \
	$(LIBGCC) $(LIBC) -T test002.x -Map test002.map

test002.objdump:test002.elf
	h8300-elf-objdump -x -t -d test002.elf > test002.objdump

test002.log:test002.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test002.lof:test002.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~
