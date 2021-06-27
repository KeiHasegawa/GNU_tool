all:hello.elf hello.objdump 

start.o:start.S
	microblaze-elf-as -o start.o -g start.S

hello.o:hello.c
	microblaze-elf-gcc -o hello.o -g -c hello.c

dummy.o:dummy.c
	microblaze-elf-gcc -o dummy.o -g -c dummy.c

DIR = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/microblaze-elf/10.2.0

hello.elf:start.o hello.o dummy.o
	microblaze-elf-ld -o hello.elf start.o hello.o dummy.o \
	-lc -L$(DIR) -lgcc -Map hello.map

hello.objdump:hello.elf
	microblaze-elf-objdump -x -t -d hello.elf > hello.objdump

clean:
	rm -f *.o *.elf *.map *.objdump *~
