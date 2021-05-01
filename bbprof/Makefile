PROG = bbprof.exe

all:$(PROG)

UNAME := $(shell uname)
ifneq (,$(findstring CYGWIN,$(UNAME)))
	MY_COFF_OBJ = my_coffgen.o
endif

OBJS = bbprof5.o bbprof3_0.o my_dwarf2.o

BINUTILS = /home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1
ifneq (,$(findstring CYGWIN,$(UNAME)))
	BINUTILS = d:/home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1
endif

ifneq (,$(findstring CYGWIN,$(UNAME)))
	LIB_INTL_FLAGS = -lintl
endif

LIB_FLAG = -lbfd -liberty -L$(BINUTILS)/libiberty -ldl -lz $(LIB_INTL_FLAGS)
EXTRA_LIB = $(BINUTILS)/opcodes/libopcodes.a

$(PROG):$(OBJS)
	$(CXX) -o $(PROG) $(OBJS) $(LIB_FLAG) $(EXTRA_LIB)

DEBUG_FLAG = -g
EXTRA_DEFINE = -DPACKAGE
EXTRA_INCUDE = -I$(BINUTILS)/bfd -I$(BINUTILS)/include

%.o : %.cpp
	$(CXX) $(DEBUG_FLAG) $(EXTRA_DEFINE) $< -c -o $@

bbprof3_0.o : bbprof3_0.c
	gcc $(DEBUG_FLAG) $(EXTRA_INCUDE) $(EXTRA_DEFINE) $< -c -o $@

my_dwarf2.o : my_dwarf2.c
	gcc $(DEBUG_FLAG) $(EXTRA_INCUDE) $< -c -o $@ -DDEBUGDIR=\".\"

my_coffgen.o : my_coffgen.c
	gcc $(DEBUG_FLAG) $(EXTRA_INCUDE) $< -c -o $@

clean:
	rm -f $(PROG) $(OBJS)
