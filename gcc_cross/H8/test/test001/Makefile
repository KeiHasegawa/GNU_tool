all:hello.elf hello.objdump TAGS hello.lof

hello.elf:hello.c
	h8300-elf-gcc -g3 -o hello.elf hello.c -Wl,-Map -Wl,hello.map

hello.elf:Makefile

hello.objdump:hello.elf
	h8300-elf-objdump -x -d hello.elf > hello.objdump

TAGS:hello.elf
	mktags.exe -o TAGS -e hello.elf

hello.log:hello.elf
	echo quit | wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@ 2>&1

hello.lof:hello.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.elf *.map *.objdump TAGS *.log *~
