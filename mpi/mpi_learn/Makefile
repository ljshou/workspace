CC = mpicc
CDEFS =
CFLAGS = -O2 -Wall -fomit-frame-pointer -g -std=c99 $(CDEFS)
LDFLAGS = -lm

BIN = std_send_recv rsendrecv

all: $(BIN)

std_send_recv: std_send_recv.o 
	$(CC) -o $@ $^ $(LDFLAGS)

rsendrecv: rsendrecv.o 
	$(CC) -o $@ $^ $(LDFLAGS)

ssendrecv: ssendrecv.o 
	$(CC) -o $@ $^ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

clean:
	/bin/rm -f *.o $(BIN) 

