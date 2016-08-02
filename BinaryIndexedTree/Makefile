CC=g++
CFLAGS=-lstdc++
CCFLAGS=-std=c++11 -fpermissive

default: BIT.exe

BIT.exe: BITOperations.o main.o
	$(CC) $(CFLAGS) -o BIT.exe BITOperations.o main.o

BITOperations.o:
	 $(CC) $(CCFLAGS) -c BITOperations.cpp

main.o:
	$(CC) $(CCFLAGS) -c main.cpp
clean:
	rm -rf *.o *.exe *.a
