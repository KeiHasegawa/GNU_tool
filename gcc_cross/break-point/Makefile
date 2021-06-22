all:start.elf start.elf.objdump

start.o:start.S
	arm-elf-as -g start.S -o start.o

start.elf:start.o start.x
	arm-elf-ld -o start.elf start.o -T start.x -Map start.map


start.elf.objdump:start.elf
	arm-elf-objdump -x -d start.elf > start.elf.objdump

clean:
	rm -f start.o start.elf start.elf.objdump start.map *~
