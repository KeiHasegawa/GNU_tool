all:test016.lof

test016.elf:test016.c
	h8300-elf-gcc -g -o $@ $<

test016.log:test016.elf
	wdog.exe -v echo quit | h8300-elf-gdb -q -x gdbcom $< > $@ 2>&1 || echo FAIL

test016.lof:test016.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.elf *.log *.objdump *~
