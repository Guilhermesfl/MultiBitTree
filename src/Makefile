IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=../.obj
LDIR =../lib

LIBS=

_DEPS = mtrie.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = mtrie.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mtrie: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
