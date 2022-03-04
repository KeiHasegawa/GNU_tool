all:test.objdump test.lof

include ../Makefile.common

test.elf:test.o
	d30v-elf-ld -o $@ $< -T ../default.x

test.log:test.elf
	echo quit | wdog.exe -v d30v-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep d30v-elf-gdb | awk '{print $$2}'`

test.lof:test.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	echo PASS
	touch $@
