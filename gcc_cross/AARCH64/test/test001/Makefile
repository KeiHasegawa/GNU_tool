all:hello.elf hello.objdump hello.lof

hello.elf:hello.o
	aarch64-elf-ld -o hello.elf start.o hello.o dummy.o -Map hello.map \
-lc

hello.elf:start.o
hello.elf:dummy.o

%.o : %.c
	aarch64-elf-gcc -g -c $< -o $@

%.o : %.S
	aarch64-elf-as -g $< -o $@

hello.objdump:hello.elf
	aarch64-elf-objdump -x -d hello.elf > hello.objdump

hello.log:hello.elf gdbcom
	wdog.exe -v aarch64-elf-gdb -q -x gdbcom hello.elf > hello.log

hello.lof:hello.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *~ *.o *.elf *.map hello.log hello.objdump


hello.o:hello.c

dummy.o:dummy.c

