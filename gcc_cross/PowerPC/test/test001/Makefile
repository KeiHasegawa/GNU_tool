all:hello.objdump hello.lof

PREFIX = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG

hello.elf:hello.c
	ppc-elf-gcc -g -o hello.elf hello.c \
	$(PREFIX)/ppc-elf/lib/sim-crt0.o -lc -lsim

hello.objdump:hello.elf
	ppc-elf-objdump -x -d $< > $@

hello.log:hello.elf gdbcom
	wdog.exe -v ppc-elf-gdb -q -x gdbcom $< > $@

hello.lof:hello.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.elf *.objdump *.log *~
