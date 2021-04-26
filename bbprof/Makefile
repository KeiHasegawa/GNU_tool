PROG = bbprof.exe

all:$(PROG)

OBJS = bbprof3.o bbprof3_0.o my_dwarf2.o

BINUTILS = /home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1

UNAME := $(shell uname)
ifneq (,$(findstring CYGWIN,$(UNAME)))
	LIB_INTL_FLAGS = -lintl
endif

LIB_FLAG = -lbfd -liberty -L$(BINUTILS)/libiberty -ldl -lz $(LIB_INTL_FLAGS)

$(PROG):$(OBJS)
	$(CXX) -o $(PROG) $(OBJS) $(LIB_FLAG)

DEBUG_FLAG = -g
EXTRA_DEFINE = -DPACKAGE
EXTRA_INCUDE = -I$(BINUTILS)/bfd -I$(BINUTILS)/include

%.o : %.cpp
	$(CXX) $(DEBUG_FLAG) $(EXTRA_DEFINE) $< -c -o $@

bbprof3_0.o : bbprof3_0.c
	gcc $(DEBUG_FLAG) $(EXTRA_INCUDE) $(EXTRA_DEFINE) $< -c -o $@

my_dwarf2.o : my_dwarf2.c
	gcc $(DEBUG_FLAG) $(EXTRA_INCUDE) $< -c -o $@ -DDEBUGDIR=\".\"

clean:
	rm -f $(PROG) $(OBJS)
