all:hello.objdump hello.lof TAGS

hello.elf:hello.c
	arm-elf-gcc -o hello.elf -g hello.c

hello.objdump:hello.elf
	arm-elf-objdump -x -d $< > $@

hello.log:hello.elf gdbcom
	wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@

TAGS:hello.elf
	mktags.exe -e hello.elf

hello.lof:hello.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f hello.elf TAGS *.log *~

