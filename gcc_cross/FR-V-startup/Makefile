TESTS = test000.elf test000.objdump \
	test001.elf test001.objdump \
	test002.elf test002.objdump \
	test003.elf test003.objdump \
	test004.elf test004.objdump \
	test005.elf test005.objdump \


all:$(TESTS)

$(TESTS):Makefile

%.s:%.c
	frv-elf-gcc -S -o $@ $<

%.o:%.s
	frv-elf-as -g -o $@ $<

%.elf:%.o
	frv-elf-ld -o $@ $(basename $<)_start.o $< -Map $(basename $@).map \
	-lc -lsim

%.o:%.S
	frv-elf-as -o $@ -g $<

%.objdump:%.elf
	frv-elf-objdump -x -d $< > $@

clean:
	rm -f start.o test000.o test000.elf test000.objdump *~


test000.elf:test000_start.o
test000.elf:test000.o
test000.o:test000.s

test001.elf:test001_start.o
test001.elf:test001.o
test001.o:test001.s

test002.elf:test002_start.o
test002.elf:test002.o
test002.o:test002.s

test003.elf:test003_start.o
test003.elf:test003.o
test003.o:test003.s

test004.elf:test004_start.o
test004.elf:test004.o
test004.o:test004.s

test005.elf:test005_start.o
test005.elf:test005.o
test005.o:test005.s
