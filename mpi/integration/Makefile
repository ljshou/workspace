CC = mpicc
CDEFS =
CFLAGS = -O2 -Wall -fomit-frame-pointer -g $(CDEFS)
LDFLAGS = -lm

BIN = main main-mpi1 main_nr main_nr-mpi1 main_nr-mpi2

all: $(BIN)

main: main.o integration.o function.o
	$(CC) -o $@ $^ $(LDFLAGS)

main-mpi1: main-mpi1.o integration.o function.o
	$(CC) -o $@ $^ $(LDFLAGS)

main_nr: main_nr.o integration_nr.o function.o
	$(CC) -o $@ $^ $(LDFLAGS)

main_nr-mpi1: main_nr-mpi1.o integration_nr.o function.o
	$(CC) -o $@ $^ $(LDFLAGS)

main_nr-mpi2: main_nr-mpi2.o integration_nr.o function.o
	$(CC) -o $@ $^ $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

clean:
	/bin/rm -f *.o $(BIN) integration.dat

