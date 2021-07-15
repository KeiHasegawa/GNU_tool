all:hello.objdump

start.o:start.S
	ft32-elf-as -g --no-relax -o $@ $<

hello.o:hello.c
	ft32-elf-gcc -g -c -o $@ $<

PREFIX = /media/ca850f52-0605-42a7-9fd4-899de9edf461/work/GNU_LANG

LIBGCC = $(PREFIX)/lib/gcc/ft32-elf/10.2.0/libgcc.a

LIBC = $(PREFIX)/ft32-elf/lib/libc.a

LIBSIM = $(PREFIX)/ft32-elf/lib/libsim.a

LIBG = $(PREFIX)/ft32-elf/lib/libg.a

hello.elf:start.o hello.o hello.x
	ft32-elf-ld -o $@ start.o hello.o \
	$(LIBGCC) $(LIBC) $(LIBSIM) $(LIBG) -T hello.x -Map hello.map

#hello.elf:start.o hello.o hello.x
#	ft32-elf-ld -o $@ start.o hello.o \
#	-L$(PREFIX)/lib/gcc/ft32-elf/10.2.0 -L$(PREFIX)/ft32-elf/lib \
#	-lgcc -lc -lg -T sim.ld -Map hello.map --defsym stack=0x1000

hello.objdump:hello.elf
	ft32-elf-objdump -x -d $< > $@

clean:
	rm -f *.o *.s *.elf *.map *.objdump *~


