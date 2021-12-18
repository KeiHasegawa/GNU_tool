all:test011.objdump test011.lof

include ../Makefile.common

test011.elf:test011.o test011.x
	mips-elf-ld -o $@ $< -T $(basename $<).x

test011.log:test011.elf
	echo quit | wdog.exe -v mips-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep mips-elf-gdb | awk '{print $$2}'`

test011.lof:test011.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

