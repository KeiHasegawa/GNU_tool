all:hello.objdump hello.lof

%.o : %.c
	rx-elf-gcc -o $@ $< -c -g

hello.elf: hello.o dummy.o
	rx-elf-gcc -g -o hello.elf hello.o dummy.o -Trx-sim.ld

hello.objdump:hello.elf
	rx-elf-objdump -x -t -d hello.elf > hello.objdump

hello.log:hello.elf gdbcom
	wdog.exe -v rx-elf-gdb -q -x gdbcom $< > $@

hello.lof:hello.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.o *.elf *.objdump *.log *~
