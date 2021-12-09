all:test002.objdump test002.lof

LIBGCC = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/aarch64-elf/10.2.0/libgcc.a

test002.elf:start.o test002.o test002.x
	aarch64-elf-ld -o test002.elf start.o test002.o \
	$(LIBGCC) -T test002.x -Map test002.map

#test002.s:test002.c
#	aarch64-elf-gcc -S $< -o $@

#test002.o:test002.s
#	aarch64-elf-as -g $< -o $@

test002.o:test002.c
	aarch64-elf-gcc -o $@ $< -g -c

start.o:start.S
	aarch64-elf-as -g $< -o $@

test002.objdump:test002.elf
	aarch64-elf-objdump -x -d test002.elf > test002.objdump

test002.log:test002.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test002.lof:test002.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *~ *.s *.o *.elf *.map test002.log test002.objdump

