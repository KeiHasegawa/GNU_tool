all:test.objdump test.lof

test.o:test.S
	rl78-elf-as -o test.o -g test.S

test.elf:test.o test.x
	rl78-elf-ld -o test.elf test.o -T test.x -Map test.map

test.objdump:test.elf
	rl78-elf-objdump -x -d -g test.elf > test.objdump

test.log:test.elf gdbcom
	wdog.exe -v rl78-elf-gdb -q -x gdbcom $< > $@

test.lof:test.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~
