all:test018.objdump test018.lof

start.o:start.S
	aarch64-elf-as -o start.o -g start.S

test018.s:test018.c
	aarch64-elf-gcc -o test018.s -g -S test018.c

test018.o:test018.s
	aarch64-elf-as -o test018.o test018.s

test018.elf:start.o test018.o test018.x
	aarch64-elf-ld -o test018.elf start.o test018.o \
	-T test018.x -Map test018.map

test018.objdump:test018.elf
	aarch64-elf-objdump -x -t -d -g test018.elf > test018.objdump

test018.log:test018.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test018.lof:test018.log
	wdog.exe -v dfif $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~


