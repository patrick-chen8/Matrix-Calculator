CC = g++
DEBUG = -g -pedantic-errors
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: Matrix.o p1.o
	$(CC) $(LFLAGS) -o p1 Matrix.o p1.o

Matrix.o: Matrix.cpp
	$(CC) $(CFLAGS) Matrix.cpp

p1.o: p1.cpp
	$(CC) $(CFLAGS) p1.cpp

run: compile
	./p1

clean:
	rm -f p1
	rm -f *.o
