all:test008.objdump test008.lof

start.o:start.S
	arm-elf-as -o $@ -g $<


test008.s:test008.c
	arm-elf-gcc -o $@ -S $< -g

test008.o:test008.s
	arm-elf-as -o $@ $<

test008.elf:start.o test008.o test008.x
	arm-elf-ld -o $@ start.o test008.o -T test008.x -Map test008.map

test008.objdump:test008.elf
	arm-elf-objdump -x -d -g $< > $@

test008.log:test008.elf gdbcom
	wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@ 

test008.lof:test008.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~

