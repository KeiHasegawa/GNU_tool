all:hello.objdump hello.lof

hello.elf:hello.c
	rl78-elf-gcc -g -o hello.elf hello.c

hello.objdump:hello.elf
	rl78-elf-objdump -x -d $< > $@

hello.log:hello.elf gdbcom
	wdog.exe -v rl78-elf-gdb -q -x gdbcom $< > $@

hello.lof:hello.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.elf *.objdump *.log *~
