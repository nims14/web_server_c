CC = gcc
CFLAGS = -O2 -Wall -I ..

all: adder divide

adder: adder.c
	$(CC) $(CFLAGS) -o adder adder.c

divide: divide.c
	$(CC) $(CFLAGS) -o divide divide.c

clean:
	rm -f adder divide *~ *.exe
