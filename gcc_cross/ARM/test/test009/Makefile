all:test009.objdump test009.lof

start.o:start.S
	arm-elf-as -o $@ -g $<


test009.s:test009.c
	arm-elf-gcc -o $@ -S $< -g

test009.o:test009.s
	arm-elf-as -o $@ $<

test009.elf:start.o test009.o test009.x
	arm-elf-ld -o $@ start.o test009.o -T test009.x -Map test009.map

test009.objdump:test009.elf
	arm-elf-objdump -x -d -g $< > $@

test009.log:test009.elf gdbcom
	wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@

test009.lof:test009.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~

