all:test007.objdump test007.lof

test007.o:test007.S
	aarch64-elf-as -o $@ -g $<

test007.elf:test007.o test007.x
	aarch64-elf-ld -o $@ test007.o -T test007.x -Map test007.map

test007.objdump:test007.elf
	aarch64-elf-objdump -x -d -g $< > $@

test007.log:test007.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom $< > $@

test007.lof:test007.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.map *.objdump *.log *~

