all:test005.objdump test005.lof

test005.o:test005.S
	aarch64-elf-as -o $@ -g $<

test005.elf:test005.o test005.x
	aarch64-elf-ld -o $@ test005.o -T test005.x -Map test005.map

test005.objdump:test005.elf
	aarch64-elf-objdump -x -d -g $< > $@

test005.log:test005.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test005.lof:test005.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~

