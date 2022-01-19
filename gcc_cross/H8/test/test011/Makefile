all:test.lof

test.elf:test.c
	h8300-elf-gcc -g -o $@ $<

test.log:test.elf
	wdog.exe -v echo quit | h8300-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test.lof:test.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.elf *.log *.objdump *~
