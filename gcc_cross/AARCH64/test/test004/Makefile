all:test004.objdump test004.lof

test004.o:test004.S
	aarch64-elf-as -o $@ -g $<

test004.elf:test004.o test004.x
	aarch64-elf-ld -o $@ test004.o -T test004.x -Map test004.map

test004.objdump:test004.elf
	aarch64-elf-objdump -x -d -g $< > $@

test004.log:test004.elf
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test004.lof:test004.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~

