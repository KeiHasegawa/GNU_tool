all:test005.objdump test005.lof

start.o:start.S
	rx-elf-as -o $@ -g $<

test005.s:test005.c
	rx-elf-gcc -o $@ -S $< -g

test005.o:test005.s
	rx-elf-as -o $@ $<

test005.elf:start.o test005.o test005.x
	rx-elf-ld -o $@ start.o test005.o -T test005.x -Map test005.map

test005.objdump:test005.elf
	rx-elf-objdump -x -d -g $< > $@

test005.log:test005.elf gdbcom
	wdog.exe -v rx-elf-gdb -q -x gdbcom $< > $@

test005.lof:test005.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
