all:test011.objdump test011.lof

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/aarch64-elf/10.2.0/libgcc.a

test011.elf:start.o test011.o test011.x
	aarch64-elf-ld -o test011.elf start.o test011.o \
	$(LIBGCC) -T test011.x -Map test011.map

#test011.s:test011.c
#	aarch64-elf-gcc -g -S $< -o $@

#test011.o:test011.s
#	aarch64-elf-as -c $< -o $@

test011.o:test011.c
	aarch64-elf-gcc -o $@ $< -g -c

start.o:start.S
	aarch64-elf-as -g $< -o $@

test011.objdump:test011.elf
	aarch64-elf-objdump -x -d -g test011.elf > test011.objdump

test011.log:test011.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test011.lof:test011.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *~ *.s *.o *.elf *.map test011.log test011.objdump

