all:test010.objdump test010.lof

test010.o:test010.S
	aarch64-elf-as -o $@ -g $<

test010.elf:test010.o test010.x
	aarch64-elf-ld -o $@ test010.o -T test010.x -Map test010.map

test010.objdump:test010.elf
	aarch64-elf-objdump -x -d -g $< > $@

test010.log:test010.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test010.lof:test010.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *~

