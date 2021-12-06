all:test004.objdump test004.lof

start.o:start.S
	h8300-elf-as -o start.o -g start.S

test004.s:test004.c
	h8300-elf-gcc -o test004.s -g -S test004.c

test004.o:test004.s
	h8300-elf-as -o $@ $<

test004.elf:start.o test004.o test004.x
	h8300-elf-ld -o test004.elf start.o test004.o \
	-T test004.x -Map test004.map

test004.objdump:test004.elf
	h8300-elf-objdump -x -t -d -g test004.elf > test004.objdump

test004.log:test004.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test004.lof:test004.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.s *.o *.elf *.objdump *.map *.log *~
