all:test010.objdump test010.lof

start.o:start.S
	arm-elf-as -o $@ -g $<


test010.s:test010.c
	arm-elf-gcc -o $@ -S $< -g

test010.o:test010.s
	arm-elf-as -o $@ $<

test010.elf:start.o test010.o test010.x
	arm-elf-ld -o $@ start.o test010.o -T test010.x -Map test010.map

test010.objdump:test010.elf
	arm-elf-objdump -x -d -g $< > $@

test010.log:test010.elf gdbcom
	wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@

test010.lof:test010.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~

