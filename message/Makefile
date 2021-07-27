all:a.out a.i b.out b.i c.out c.i TAGS


INCLUDE=-I/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/glibc-2.33/install/include


LIB=/media/ca850f52-0605-42a7-9fd4-899de9edf461/work/glibc-2.33/install/lib

%.o:%.c
	gcc -g3 -o $@ -c $< $(INCLUDE)

%.out:%.o
	/usr/local/libexec/gcc/i686-pc-linux-gnu/10.2.0/collect2 \
-o $@ $< \
--eh-frame-hdr -m elf_i386 -dynamic-linker \
$(LIB)/ld-linux.so.2 \
$(LIB)/crt1.o \
$(LIB)/crti.o \
/usr/local/lib/gcc/i686-pc-linux-gnu/10.2.0/crtbegin.o \
$(LIB)/libc.so \
/usr/local/lib/gcc/i686-pc-linux-gnu/10.2.0/crtend.o \
$(LIB)/crtn.o

%.i:%.c
	gcc -g3 -o $@ -E $< $(INCLUDE)

TAGS:a.out b.out c.out
	mktags.exe -e -o $@ a.out b.out c.out

a.out:Makefile
b.out:Makefile
c.out:Makefile
a.out:a.o
b.out:b.o
c.out:c.o

clean:
	rm -f *.o *.out *~ TAGS *.i *.j

