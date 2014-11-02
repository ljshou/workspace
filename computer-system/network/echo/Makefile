CC = gcc
CFLAGS = -O2 -Wall -I .

# This flag includes the Pthreads library on a Linux box.
# Others systems will probably require something different.
LIB = -lpthread

all: echoclient echoserver

echoclient: echoclient.c csapp.o
	$(CC) $(CFLAGS) -o echoclient echoclient.c csapp.o $(LIB)

echoserver: echoserveri.c csapp.o echo.o
	$(CC) $(CFLAGS) -o echoserver echoserveri.c csapp.o echo.o $(LIB)

echo.o:
	$(CC) $(CFLAGS) -c echo.c

csapp.o:
	$(CC) $(CFLAGS) -c csapp.c

clean:
	rm -f *.o echoclient echoserver *~

