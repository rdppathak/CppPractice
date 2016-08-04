CC=g++
CFLAGS=-lstdc++
CCFLAGS=-std=c++11

default: RedBlack.exe

RedBlack.exe: RedBlackTreeOperations.o main.o
	$(CC) $(CFLAGS) -o RedBlack.exe RedBlackTreeOperations.o main.o

RedBlackTreeOperations.o:
	 $(CC) $(CCFLAGS) -c RedBlackTreeOperations.cpp

main.o:
	$(CC) $(CCFLAGS) -c main.cpp
clean:
	rm -rf *.o *.exe *.a
