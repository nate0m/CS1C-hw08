CC = g++

all: hw08

hw08: hw08.cpp
	$(CC) hw08.cpp -o hw08.o

clean:
	rm hw08 *.o

tar:
	tar cf hw08.tar hw08.scr Makefile hw08.cpp
