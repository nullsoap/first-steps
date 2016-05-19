CC=g++
CFLAGS=-Wall
INCDIR=-I..\SFML-2.3.2\include
LIBDIR=-L..\SFML-2.3.2\lib

all:
	$(CC) $(CFLAGS) $(INCDIR) $(LIBEDIR) main.cpp -o main.exe

clean:
	rm -f *o *exe