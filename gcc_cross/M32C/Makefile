all:hello.objdump

start.o:start.S
	m32c-elf-as -o start.o -g start.S

#hello.s:hello.c
#	m32c-elf-gcc -o hello.s -S hello.c
#
#hello.o:hello.s
#	m32c-elf-as -o hello.o -g hello.s

hello.o:hello.c
	m32c-elf-gcc -o hello.o -g -c hello.c

dummy.o:dummy.c
	m32c-elf-gcc -o dummy.o -g -c dummy.c

DIR1 = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/m32c-elf/lib
DIR2 = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG/lib/gcc/m32c-elf/10.2.0

hello.elf:start.o hello.o dummy.o hello.x
	m32c-elf-ld -o hello.elf start.o  hello.o dummy.o \
	-L$(DIR1) -lc -L$(DIR2) -lgcc -T hello.x -Map hello.map

hello.objdump:hello.elf
	m32c-elf-objdump -x -d hello.elf > hello.objdump

clean:
	rm -f *.s *.o *.elf *.map *.objdump *~
