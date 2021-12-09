all:test012.objdump test012.lof

test012.elf:start.o test012.o test012.x
	aarch64-elf-ld -o test012.elf start.o test012.o \
	-T test012.x -Map test012.map

#test012.s:test012.c
#	aarch64-elf-gcc -g -S $< -o $@

#test012.o:test012.s
#	aarch64-elf-as $< -o $@

test012.o:test012.c
	aarch64-elf-gcc -o $@ $< -g -c

start.o:start.S
	aarch64-elf-as -g $< -o $@

test012.objdump:test012.elf
	aarch64-elf-objdump -x -d test012.elf > test012.objdump

test012.log:test012.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test012.lof:test012.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *~ *.s *.o *.elf *.map test012.log test012.objdump

