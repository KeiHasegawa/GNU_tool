all:hello.objdump

%.o : %.c
	rx-elf-gcc -o $@ $< -c -O2 -g

hello.elf: hello.o dummy.o
	rx-elf-gcc -o hello.elf hello.o dummy.o -Trx-sim.ld

hello.objdump:hello.elf
	rx-elf-objdump -x -t -d hello.elf > hello.objdump

clean:
	rm -f *.o *.elf *.objdump *~
