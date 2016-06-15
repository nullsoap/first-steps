CC=g++
CFLAGS=-Wall
INCDIR=-IT:\dropbox\code\SFML-2.3.2\include
LNKFLG=-LT:\dropbox\code\SFML-2.3.2\lib -lsfml-graphics -lsfml-window -lsfml-system
objects=main.o game.o splashscreen.o mainmenu.o

all: $(objects)
	$(CC) $(CFLAGS) $(INCDIR) -o main.exe $(objects) $(LNKFLG)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCDIR) -c main.cpp
	
game.o: game.cpp game.h
	$(CC) $(CFLAGS) $(INCDIR) -c game.cpp
	
splashscreen.o: splashscreen.cpp splashscreen.h
	$(CC) $(CFLAGS) $(INCDIR) -c splashscreen.cpp
	
mainmenu.o: mainmenu.cpp mainmenu.h
	$(CC) $(CFLAGS) $(INCDIR) -c mainmenu.cpp
	
clean:
	rm *.o *.exe
	