all:test009.objdump test009.lof

include ../Makefile.common

test009.elf:test009.o test009.x
	lm32-elf-ld -o $@ $< -T $(basename $<).x

test009.log:test009.elf
	echo quit | wdog.exe -v lm32-elf-gdb -q -x gdbcom $< > $@ 2>&1 &
	sleep 1
	kill -INT `ps -ef | grep lm32-elf-gdb | awk '{print $$2}'`

test009.lof:test009.log
	grep -q 'Program received signal SIGINT, Interrupt.' $< || grep -q 'Program received signal SIGINT, Interrupt.' $<
	echo PASS
	touch $@

