all:test003.objdump test003.lof

test003.o:test003.S
	rl78-elf-as -o test003.o -g test003.S

test003.elf:test003.o test003.x
	rl78-elf-ld -o test003.elf test003.o -T test003.x -Map test003.map

test003.objdump:test003.elf
	rl78-elf-objdump -x -d -g test003.elf > test003.objdump

test003.log:test003.elf gdbcom
	wdog.exe -v rl78-elf-gdb -q -x gdbcom $< > $@

test003.lof:test003.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~
