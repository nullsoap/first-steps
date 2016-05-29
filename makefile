CC=g++
CFLAGS=-Wall
INCDIR=-IT:\dropbox\code\SFML-2.3.2\include
LNKFLG=-LT:\dropbox\code\SFML-2.3.2\lib -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CC) $(CFLAGS) $(INCDIR) main.cpp -o main.exe $(LNKFLG)

clean:
	del /q *.o *.exe