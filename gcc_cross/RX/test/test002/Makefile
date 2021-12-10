all:test002.objdump test002.lof

start.o:start.S
	rx-elf-as -o $@ -g $<

#test002.s:test002.c
#	rx-elf-gcc -o $@ -S $<

#test002.o:test002.s
#	rx-elf-as -o $@ -g $<

test002.o:test002.c
	rx-elf-gcc -o $@ $< -c -g

#test002_sub.s:test002_sub.c
#	rx-elf-gcc -o $@ -S $<

#test002_sub.o:test002_sub.s
#	rx-elf-as -o $@ -g $<

test002_sub.o:test002_sub.c
	rx-elf-gcc -o $@ $< -c -g

test002.elf:start.o test002.o test002_sub.o test002.x
	rx-elf-ld -o $@ start.o test002.o test002_sub.o \
	-T test002.x -Map test002.map

test002.objdump:test002.elf
	rx-elf-objdump -x -d -g $< > $@

test002.log:test002.elf gdbcom
	wdog.exe -v rx-elf-gdb -q -x gdbcom $< > $@

test002.lof:test002.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
