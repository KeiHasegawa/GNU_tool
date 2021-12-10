all:test004.objdump test004.lof

start.o:start.S
	rx-elf-as -o $@ -g $<

test004.s:test004.c
	rx-elf-gcc -o $@ -S $< -g

test004.o:test004.s
	rx-elf-as -o $@ $<

test004_sub.s:test004_sub.c
	rx-elf-gcc -o $@ -S $< -g

test004_sub.o:test004_sub.s
	rx-elf-as -o $@ $<

test004.elf:start.o test004.o test004_sub.o test004.x
	rx-elf-ld -o $@ start.o test004.o test004_sub.o \
	-T test004.x -Map test004.map

test004.objdump:test004.elf
	rx-elf-objdump -x -d -g $< > $@

test004.log:test004.elf gdbcom
	wdog.exe -v rx-elf-gdb -q -x gdbcom $< > $@

test004.lof:test004.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
