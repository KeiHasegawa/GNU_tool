all:test000.elf test001.elf


test000.elf:test000.o test000.x
test001.elf:test001.o test001.x

%.o:%.S
	h8300-elf-as -o $@ -g $<

%.elf:%.o
	h8300-elf-ld -o $@ $< -T $(basename $<).x -Map $(basenanme $@).map


clean:
	rm -f *.elf *.o *.map *~

