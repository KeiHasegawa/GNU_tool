all:test008.objdump test008.lof

start.o:start.S
	rl78-elf-as -o $@ -g $<

test008.s:test008.c
	rl78-elf-gcc -o $@ -S $< -g

test008.o:test008.s
	rl78-elf-as -o $@ $<

LIBGCC =/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/rl78-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/rl78-elf/lib/libc.a

test008.elf:start.o test008.o test008.x
	rl78-elf-ld -o $@ start.o test008.o \
	$(LIBGCC) $(LIBC) -T test008.x -Map test008.map

test008.objdump:test008.elf
	rl78-elf-objdump -x -d -g $< > $@

test008.log:test008.elf gdbcom
	wdog.exe -v rl78-elf-gdb -q -x gdbcom $< > $@

test008.lof:test008.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
