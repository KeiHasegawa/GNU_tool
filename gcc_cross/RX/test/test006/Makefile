all:test006.objdump test006.lof

start.o:start.S
	rx-elf-as -o $@ -g $<

test006.s:test006.c
	rx-elf-gcc -o $@ -S $< -g

test006.o:test006.s
	rx-elf-as -o $@ $<

test006.elf:start.o test006.o test006.x
	rx-elf-ld -o $@ start.o test006.o -T test006.x -Map test006.map

test006.objdump:test006.elf
	rx-elf-objdump -x -d -g $< > $@

test006.log:test006.elf gdbcom
	wdog.exe -v rx-elf-gdb -q -x gdbcom $< > $@

test006.lof:test006.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
