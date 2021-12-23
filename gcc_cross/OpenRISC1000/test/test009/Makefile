all:test009.objdump test009.lof

include ../Makefile.common

test009.elf:test009.o test009.x
	or1k-elf-ld -o $@ $< -T $(basename $<).x

test009.log:test009.elf
	echo quit | wdog.exe -v or1k-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep or1k-elf-gdb | awk '{print $$2}'`

test009.lof:test009.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	touch $@

