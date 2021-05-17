PROG = mktags.exe

all:$(PROG)

OBJS = mktags.o

UNAME := $(shell uname)

ifneq (,$(findstring CYGWIN,$(UNAME)))
	BINUTILS_DIR = d:/home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1
else
	BINUTILS_DIR = /home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1
endif


LIB_LIBIBERTY_FLAG = -L$(BINUTILS_DIR)/libiberty

ifneq (,$(findstring CYGWIN,$(UNAME)))
	LIB_INTL_FLAG = -lintl
endif

$(PROG):$(OBJS)
	g++ -o $(PROG) $(OBJS) $(EXTRA_LIBS)

EXTRA_DEFINES = -DPACKAGE -DBUG_REPRODUCE

%.o : %.cpp
	g++ -g3 -c $(EXTRA_DEFINES) -I$(BINUTILS_DIR)/include $< -o $@

EXTRA_INCLUDES = -I$(BINUTILS_DIR)/binutils -I$(BINUTILS_DIR)/include \
		 -I$(BINUTILS_DIR)/bfd

%.o : %.c
	gcc -g3 -c $(EXTRA_INCLUDES) $< -o $@

clean:
	rm -f $(PROG) $(OBJS)
