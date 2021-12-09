all:test017.objdump test017.lof

start.o:start.S
	aarch64-elf-as -o start.o -g start.S

test017.s:test017.c
	aarch64-elf-gcc -o test017.s -g -S test017.c

test017.o:test017.s
	aarch64-elf-as -o test017.o test017.s

test017.elf:start.o test017.o test017.x
	aarch64-elf-ld -o test017.elf start.o test017.o \
	-T test017.x -Map test017.map

test017.objdump:test017.elf
	aarch64-elf-objdump -x -t -d -g test017.elf > test017.objdump

test017.log:test017.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test017.lof:test017.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~


