all:test010.objdump test010.lof

include ../Makefile.common

test010.elf:test010.o test010.x
	v850-elf-ld -o $@ $< -T $(basename $<).x

test010.log:test010.elf
	echo quit | wdog.exe -v v850-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep v850-elf-gdb | awk '{print $$2}'`

test010.lof:test010.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

