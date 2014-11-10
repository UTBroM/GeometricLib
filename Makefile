CC=gcc
LIBFLAGS=-L.
INCLUDEFLAGS=-I. -I/usr/include 
CFLAGS=-Wall -Werror -ansi -pedantic -fpic -g

LIB=libPolygon.so
LIBNAME=Polygon
LIBFILES=polygon
LIBSRC=$(LIBFILES:=.c)
LIBOBJ=$(LIBFILES:=.o)

EXEC=polylol
SRCFILES=polygonmain
SRC=$(SRCFILES:=.c)
OBJ=$(SRC:.c=.o)


all: $(EXEC)

lib: $(LIB)

$(EXEC): $(OBJ) $(LIB)
	@echo "\n Generating the executable " $@
	$(CC) $(OBJ) -l$(LIBNAME) $(LIBFLAGS) -o $@

$(LIB): $(LIBOBJ)
	@echo "\n Generating the library " $@
	$(CC) $(CFLAGS) -shared $^ -o $@

%.o: %.c
	@echo "\n Generating " $@ " from " $<
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDEFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC) *.so
