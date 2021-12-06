all:test017.lof


test017.elf:test017.o test017.x

%.o:%.S
	h8300-elf-as -o $@ -g $<

%.elf:%.o
	h8300-elf-ld -o $@ $< -T $(basename $<).x -Map $(basenanme $@).map

test017.log:test017.elf
	wdog.exe -v h8300-elf-gdb -q -x gdbcom $< > $@

test017.lof:test017.log
	wdog.exe -v diff $< $@
	touch $@

clean:
	rm -f *.elf *.o *.map *.log *~

