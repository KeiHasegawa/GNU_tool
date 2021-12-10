all:test003.objdump test003.lof

start.o:start.S
	rx-elf-as -o $@ -g $<

#test003.s:test003.c
#	rx-elf-gcc -o $@ -S $< -g

#test003.o:test003.s
#	rx-elf-as -o $@ $<

test003.o:test003.c
	rx-elf-gcc -o $@ $< -c -g

#test003_sub.s:test003_sub.c
#	rx-elf-gcc -o $@ -S $< -g

#test003_sub.o:test003_sub.s
#	rx-elf-as -o $@ $<

test003_sub.o:test003_sub.c
	rx-elf-gcc -o $@ $< -c -g

test003.elf:start.o test003.o test003_sub.o test003.x
	rx-elf-ld -o $@ start.o test003.o test003_sub.o \
	-T test003.x -Map test003.map

test003.objdump:test003.elf
	rx-elf-objdump -x -d -g $< > $@

test003.log:test003.elf gdbcom
	wdog.exe -v rx-elf-gdb -q -x gdbcom $< > $@

test003.lof:test003.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *.log *~
