CC=g++
CFLAGS=-lstdc++
CCFLAGS=-std=c++11

default: avl.exe

avl.exe: node.o main.o
	$(CC) $(CFLAGS) -o avl.exe node.o main.o

node.o:
	 $(CC) $(CCFLAGS) -c Node.cpp

main.o:
	$(CC) $(CCFLAGS) -c main.cpp

clean:
	rm -rf *.o *.exe *.a
