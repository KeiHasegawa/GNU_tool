all:test005.objdump test005.lof

start.o:start.S
	rl78-elf-as -o $@ -g $<

#test005.s:test005.c
#	rl78-elf-gcc -o $@ -S $< -g

#test005.o:test005.s
#	rl78-elf-as -o $@ $<

test005.o:test005.c
	rl78-elf-gcc -o $@ $< -c -g

LIBGCC =/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/rl78-elf/10.2.0/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/rl78-elf/lib/libc.a

test005.elf:start.o test005.o test005.x
	rl78-elf-ld -o $@ start.o test005.o \
	$(LIBGCC) $(LIBC) -T test005.x -Map test005.map

test005.objdump:test005.elf
	rl78-elf-objdump -x -d $< > $@

test005.log:test005.elf
	wdog.exe -v rl78-elf-gdb -q -x gdbcom $< > $@

test005.lof:test005.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
