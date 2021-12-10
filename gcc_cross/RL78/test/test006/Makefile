all:test006.objdump test006.lof

start.o:start.S
	rl78-elf-as -o $@ -g $<

test006.s:test006.c
	rl78-elf-gcc -o $@ -S $< -g

test006.o:test006.s
	rl78-elf-as -o $@ $<

LIBGCC =/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/rl78-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/rl78-elf/lib/libc.a

test006.elf:start.o test006.o test006.x
	rl78-elf-ld -o $@ start.o test006.o \
	$(LIBGCC) $(LIBC) -T test006.x -Map test006.map

test006.objdump:test006.elf
	rl78-elf-objdump -x -d -g $< > $@

test006.log:test006.elf gdbcom
	wdog.exe -v rl78-elf-gdb -q -x gdbcom $< > $@

test006.lof:test006.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
