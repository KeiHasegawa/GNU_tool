all:test015.objdump test015.lof

start.o:start.S
	aarch64-elf-as -o start.o -g start.S

test015.s:test015.c
	aarch64-elf-gcc -o test015.s -g -S test015.c

test015.o:test015.s
	aarch64-elf-as -o test015.o test015.s

test015.elf:start.o test015.o test015.x
	aarch64-elf-ld -o test015.elf start.o test015.o \
	-T test015.x -Map test015.map

test015.objdump:test015.elf
	aarch64-elf-objdump -x -t -d -g test015.elf > test015.objdump

test015.log:test015.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test015.lof:test015.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~


