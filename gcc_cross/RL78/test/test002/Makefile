all:test002.objdump test002.lof

start.o:start.S
	rl78-elf-as -o $@ -g $<

#test002.s:test002.c
#	rl78-elf-gcc -o $@ -S $<

#test002.o:test002.s
#	rl78-elf-as -o $@ -g $<

test002.o:test002.c
	rl78-elf-gcc -o $@ $< -c -g

LIBGCC =/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/rl78-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/rl78-elf/lib/libc.a

test002.elf:start.o test002.o test002.x
	rl78-elf-ld -o $@ start.o test002.o \
	$(LIBGCC) $(LIBC) -T test002.x -Map test002.map

test002.objdump:test002.elf
	rl78-elf-objdump -x -d $< > $@

test002.log:test002.elf gdbcom
	wdog.exe -v rl78-elf-gdb -q -x gdbcom $< > $@

test002.lof:test002.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
