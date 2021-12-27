all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o test.x
	arm-elf-ld -o $@ $< -T $(basename $<).x

test.log:test.elf
	echo quit | wdog.exe -v arm-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep arm-elf-gdb | awk '{print $$2}'`

test.lof:test.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

