CC=g++
CFLAGS=-g -Wall

all: add-nbo

add-nbo: add-nbo.o
	$(CC) $(CFLAGS) -o add-nbo add-nbo.o

add-nbo.o: add-nbo.cpp
	$(CC) $(CFLAGS) -c add-nbo.cpp

clean:
	rm -f add-nbo *.o