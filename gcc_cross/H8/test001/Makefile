all:hello.elf hello.objdump TAGS hello.lof

hello.elf:hello.c
	h8300-elf-gcc -g3 -o hello.elf hello.c -Wl,-Map -Wl,hello.map

hello.elf:Makefile

hello.objdump:hello.elf
	h8300-elf-objdump -x -d hello.elf > hello.objdump

TAGS:hello.elf
	mktags.exe -o TAGS -e hello.elf

hello.log:hello.elf
	h8300-elf-gdb -q -x gdbcom $< > $@

hello.lof:hello.log
	diff $< $@
	touch $@

clean:
	rm -f *.elf *.map *.objdump TAGS *.log *~
