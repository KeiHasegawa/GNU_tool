all:test016.objdump test016.lof

start.o:start.S
	aarch64-elf-as -o start.o -g start.S

#test016.s:test016.c
#	aarch64-elf-gcc -o test016.s -g -S test016.c

#test016.o:test016.s
#	aarch64-elf-as -o test016.o test016.s

test016.o:test016.c
	aarch64-elf-gcc -o $@ $< -c -g

test016.elf:start.o test016.o test016.x
	aarch64-elf-ld -o test016.elf start.o test016.o \
	-T test016.x -Map test016.map

test016.objdump:test016.elf
	aarch64-elf-objdump -x -t -d -g test016.elf > test016.objdump

test016.log:test016.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test016.lof:test016.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.map *.objdump *.log *~


