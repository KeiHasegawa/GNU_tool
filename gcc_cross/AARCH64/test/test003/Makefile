all:test003.objdump test003.lof

test003.o:test003.S
	aarch64-elf-as -o $@ -g $<

test003.elf:test003.o test003.x
	aarch64-elf-ld -o $@ test003.o -T test003.x -Map test003.map

test003.objdump:test003.elf
	aarch64-elf-objdump -x -d -g $< > $@

test003.log:test003.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom test003.elf > $@

test003.lof:test003.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~

