all:test.objdump

test.o:test.S
	z8k-coff-as -o $@ $< -g

test.coff:test.o
	z8k-coff-ld -o $@ $< -T ../test/default.x

test.objdump:test.coff
	z8k-coff-objdump -g -x -d $< > $@

clean:
	rm -f *.o *~ *.coff *.objdump
