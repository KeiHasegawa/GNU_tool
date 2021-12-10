all:test007.objdump test007.lof

start.o:start.S
	rx-elf-as -o $@ -g $<

test007.s:test007.c
	rx-elf-gcc -o $@ -S $< -g

test007.o:test007.s
	rx-elf-as -o $@ $<

test007.elf:start.o test007.o test007.x
	rx-elf-ld -o $@ start.o test007.o -T test007.x -Map test007.map

test007.objdump:test007.elf
	rx-elf-objdump -x -d -g $< > $@

test007.log:test007.elf gdbcom
	wdog.exe -v rx-elf-gdb -q -x gdbcom $< > $@

test007.lof:test007.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
