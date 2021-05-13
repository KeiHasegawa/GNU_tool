PROG = mktags.exe

all:$(PROG)

OBJS = mktags.o

EXTRA_LIBS = -lbfd -liberty \
-L/home/khasegawa/binutils-2.36.1-2.src/binutils-2.36.1/libiberty -ldl -lz

$(PROG):$(OBJS)
	g++ -o $(PROG) $(OBJS) $(EXTRA_LIBS)

EXTRA_DEFINES = -DPACKAGE

%.o : %.cpp
	g++ -g3 -c $(EXTRA_DEFINES) $< -o $@

clean:
	rm -f $(PROG) $(OBJS)
