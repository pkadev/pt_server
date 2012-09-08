IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)
ODIR=obj

_DEPS = stock.h time.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))


_OBJ = main.o html_parser.o stock.o time.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pt_srv: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
