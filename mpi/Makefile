CC = mpicc
CDEFS =
CFLAGS = -O2 -Wall -fomit-frame-pointer -g -std=c99 $(CDEFS)
LDFLAGS = -lm

BIN = cannon main split std_send_recv

all: $(BIN)

main: main.o 
	$(CC) -o $@ $^ $(LDFLAGS)

cannon: cannon.o 
	$(CC) -o $@ $^ $(LDFLAGS)

split: split.o 
	$(CC) -o $@ $^ $(LDFLAGS)

std_send_recv: std_send_recv.o 
	$(CC) -o $@ $^ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

clean:
	/bin/rm -f *.o $(BIN) 

