all:hello.elf hello.objdump

hello.elf:hello.o
	aarch64-elf-ld -o hello.elf start.o hello.o dummy.o -Map hello.map \
-lc

hello.elf:start.o
hello.elf:dummy.o

%.o : %.c
	aarch64-elf-gcc -g -c $< -o $@

%.o : %.S
	aarch64-elf-as -g $< -o $@

hello.objdump:hello.elf gdbcom
	aarch64-elf-objdump -x -d hello.elf > hello.objdump

clean:
	rm -f *~ *.o *.elf *.map hello.log hello.objdump

hello.o:hello.c

dummy.o:dummy.c

