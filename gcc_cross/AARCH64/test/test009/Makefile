all:test009.objdump test009.lof

test009.o:test009.S
	aarch64-elf-as -o $@ -g $<

test009.elf:test009.o test009.x
	aarch64-elf-ld -o $@ test009.o -T test009.x -Map test009.map

test009.objdump:test009.elf
	aarch64-elf-objdump -x -d -g $< > $@

test009.log:test009.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test009.lof:test009.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~

