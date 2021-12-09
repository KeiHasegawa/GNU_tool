all:test000.lof

test000.o:test000.S
	h8300-elf-as -o test000.o -g test000.S

test000.elf:test000.o test000.x
	h8300-elf-ld -o test000.elf test000.o -T test000.x -Map test000.map

test000.objdump:test000.elf
	h8300-elf-objdump -x -d -g test000.elf > test000.objdump

test000.log:test000.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom test000.elf > test000.log

test000.lof:test000.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~
