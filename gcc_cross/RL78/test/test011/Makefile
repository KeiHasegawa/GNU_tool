all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	rl78-elf-ld -o $@ $< -T ../default.x

test.log:test.elf
	echo quit | wdog.exe -v rl78-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep rl78-elf-gdb | awk '{print $$2}'`

test.lof:test.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	echo PASS
	touch $@

