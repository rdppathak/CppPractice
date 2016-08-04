CC=g++
CFLAGS=-lstdc++
CCFLAGS=-std=c++11

default: RedBlack.exe

RedBlack.exe: RedBlackOperations.o main.o
	$(CC) $(CFLAGS) -o RedBlack.exe RedBlackOperations.o main.o

RedBlackOperations.o:
	 $(CC) $(CCFLAGS) -c RedBlackOperations.cpp

main.o:
	$(CC) $(CCFLAGS) -c main.cpp
clean:
	rm -rf *.o *.exe *.a
