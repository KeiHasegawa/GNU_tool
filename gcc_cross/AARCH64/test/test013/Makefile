all:test013.objdump test013.lof

start.o:start.S
	aarch64-elf-as -o start.o -g start.S

test013.s:test013.c
	aarch64-elf-gcc -o test013.s -g -S test013.c

test013.o:test013.s
	aarch64-elf-as -o test013.o test013.s

test013.elf:start.o test013.o test013.x
	aarch64-elf-ld -o test013.elf start.o test013.o \
	-T test013.x -Map test013.map

test013.objdump:test013.elf
	aarch64-elf-objdump -x -t -d -g test013.elf > test013.objdump

test013.log:test013.elf gdbcom
	aarch64-elf-gdb -q -x gdbcom $< > $@

test013.lof:test013.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~


