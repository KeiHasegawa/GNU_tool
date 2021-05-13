PROG = mktags.exe

all:$(PROG)

OBJS = mktags.o

UNAME := $(shell uname)

ifneq (,$(findstring CYGWIN,$(UNAME)))
	LIB_INTL_FLAG = -lintl
else
	LIB_LIBIBERTY_FLAG = -L/home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1/libiberty
endif

EXTRA_LIBS = -lbfd -liberty $(LIB_LIBIBERTY_FLAG) -ldl -lz $(LIB_INTL_FLAG)

$(PROG):$(OBJS)
	g++ -o $(PROG) $(OBJS) $(EXTRA_LIBS)

EXTRA_DEFINES = -DPACKAGE

%.o : %.cpp
	g++ -g3 -c $(EXTRA_DEFINES) $< -o $@

clean:
	rm -f $(PROG) $(OBJS)
