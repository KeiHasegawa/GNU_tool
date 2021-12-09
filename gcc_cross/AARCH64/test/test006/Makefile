all:test006.objdump test006.lof

test006.o:test006.S
	aarch64-elf-as -o $@ -g $<

test006.elf:test006.o test006.x
	aarch64-elf-ld -o $@ test006.o -T test006.x -Map test006.map

test006.objdump:test006.elf
	aarch64-elf-objdump -x -d -g $< > $@

test006.log:test006.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test006.lof:test006.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *~

