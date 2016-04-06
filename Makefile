CC = gcc
CFLAGS = -O2 -Wall -I .
FILES = tiny.c Makefile home.html batman.gif \
	webserver.c webserver.h \
	cgi-bin/adder.c cgi-bin/divide.c cgi-bin/Makefile

# This flag includes the Pthreads library on a Linux box.
# Others systems will probably require something different.
LIB = -lpthread

all: tiny cgi tiny.tar

tiny: tiny.c webserver.o
	$(CC) $(CFLAGS) -o tiny tiny.c webserver.o $(LIB)

cgi:
	(cd cgi-bin; make)

webserver.o:
	$(CC) $(CFLAGS) -c webserver.c

tiny.tar: $(FILES)
	tar cvf tiny.tar $(FILES)

clean:
	rm -f *.o tiny *~ *.exe
	(cd cgi-bin; make clean)

