start.elf:start.o start.x
	h8300-elf-ld -o start.elf start.o -T start.x -Map start.map

start.o:start.S
	h8300-elf-as -g start.S -c -o start.o

clean:
	rm -f start.elf start.map start.o *~
