all:test003.objdump test003.lof

start.o:start.S
	arm-elf-as -o $@ -g $<

#test003.s:test003.c
#	arm-elf-gcc -o $@ -S $<

#test003.o:test003.s
#	arm-elf-as -o $@ -g $<

test003.o:test003.c
	arm-elf-gcc -o $@ $< -c -g

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/arm-elf/3.4.4/libgcc.a

LIBC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/arm-elf/lib/libc.a

test003.elf:start.o test003.o test003.x
	arm-elf-ld -o $@ start.o test003.o \
	$(LIBGCC) $(LIBC) -T test003.x -Map test003.map

test003.objdump:test003.elf
	arm-elf-objdump -x -d test003.elf > test003.objdump

test003.log:test003.elf gdbcom
	wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@

test003.lof:test003.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~
