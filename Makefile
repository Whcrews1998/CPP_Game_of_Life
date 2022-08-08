CC=g++
CFLAGS=-c -Wall

SDL-I=-I/Library/Frameworks/SDL2.framework/Headers
SDL-IMAGE-I=-I/Library/Frameworks/SDL2_image.framework/Headers

SDL-F=-F/Library/Frameworks -framework SDL2
SDL-IMAGE-F=-F/Library/Frameworks -framework SDL2_image

all: Game-of-Life
	
Game-of-Life: main.o Game.o
	$(CC) -o Game-of-Life main.o Game.o $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

Game.o: Game.cpp
	$(CC) $(CFLAGS) Game.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

clean: 
	rm -rf *o Game-of-Life
