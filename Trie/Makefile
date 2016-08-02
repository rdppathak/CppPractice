CC=g++
CFLAGS=-lstdc++
CCFLAGS=-std=c++11 -fpermissive

default: Tries.exe

Tries.exe: TrieOperations.o main.o
	$(CC) $(CFLAGS) -o Tries.exe TrieOperations.o main.o

TrieOperations.o:
	 $(CC) $(CCFLAGS) -c TrieOperations.cpp

main.o:
	$(CC) $(CCFLAGS) -c main.cpp
clean:
	rm -rf *.o *.exe *.a
