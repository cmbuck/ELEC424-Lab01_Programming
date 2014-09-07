CC=gcc
CFLAGS=-I. -g
DEPS = sort.h read_data.h
OBJ = sort.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sort: sort.o read_data.a
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o
