CC=g++
CFLAGS=-lstdc++
CCFLAGS=-std=c++11

default: btree.exe

btree.exe: BtreeOperations.o main.o
	$(CC) $(CFLAGS) -o btree.exe BtreeOperations.o main.o

BtreeOperations.o:
	 $(CC) $(CCFLAGS) -c BtreeOperations.cpp

main.o:
	$(CC) $(CCFLAGS) -c main.cpp

clean:
	rm -rf *.o *.exe *.a
