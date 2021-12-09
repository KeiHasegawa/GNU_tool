all:test008.objdump test008.lof

test008.o:test008.S
	aarch64-elf-as -o $@ -g $<

test008.elf:test008.o test008.x
	aarch64-elf-ld -o $@ test008.o -T test008.x -Map test008.map

test008.objdump:test008.elf
	aarch64-elf-objdump -x -d -g $< > $@

test008.log:test008.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test008.lof:test008.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~

