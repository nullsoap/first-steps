CC=g++
CFLAGS=-Wall
INCDIR=-IT:\dropbox\code\SFML-2.3.2\include
LNKFLG=-LT:\dropbox\code\SFML-2.3.2\lib -lsfml-graphics -lsfml-window -lsfml-system

all: main.o game.o
	$(CC) $(CFLAGS) $(INCDIR) -o main.exe main.o game.o $(LNKFLG)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCDIR) -c main.cpp
	
game.o: game.cpp game.h
	$(CC) $(CFLAGS) $(INCDIR) -c game.cpp
	
clean:
	del /q *.o *.exe