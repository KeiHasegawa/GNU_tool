TESTS = test000.elf \
	test001.elf \
	test002.elf \


all:$(TESTS)

$(TESTS):Makefile

%.s:%.c
	frv-elf-gcc -S -o $@ $<

%.o:%.s
	frv-elf-as -g -o $@ $<

%.elf:%.o
	frv-elf-ld -o $@ $(basename $<)_start.o $< -Map $(basename $@).map

test002.elf:test002.o
	frv-elf-ld -o $@ test001_start.o $< -Map $(basename $@).map -lc -lsim

%.o:%.S
	frv-elf-as -o $@ -g $<

clean:
	rm -f $(TESTS) *.map *.o *.s *~


test000.elf:test000_start.o
test000.elf:test000.o
test000.o:test000.s

test001.elf:test001_start.o
test001.elf:test001.o
test001.o:test001.s

test002.elf:test001_start.o
test002.elf:test002.o
test002.o:test002.s
