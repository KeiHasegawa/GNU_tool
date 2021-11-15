all:start.elf start.elf.objdump

start.o:start.S
	aarch64-elf-as -g start.S -o start.o

start.elf:start.o start.x
	aarch64-elf-ld -o start.elf start.o -T start.x -Map start.map


start.elf.objdump:start.elf
	aarch64-elf-objdump -x -d start.elf > start.elf.objdump

clean:
	rm -f start.o start.elf start.map start.elf.objdump *~
