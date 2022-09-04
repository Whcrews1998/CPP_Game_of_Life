CC=g++
CFLAGS=-c -Wall

SDL-I=-I./frameworks/SDL2.framework/Headers
SDL-F=-F./frameworks -framework SDL2

SDL-IMAGE-I=-I./frameworks/SDL2_image.framework/Headers
SDL-IMAGE-F=-F./frameworks -framework SDL2_image

all: Game-of-Life
	
Game-of-Life: main.o Game.o Cell.o Game-Board.o move
	$(CC) -o Game-of-Life ./obj/main.o ./obj/Game.o ./obj/game-Board.o ./obj/Cell.o $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

main.o: ./src/main.cpp
	$(CC) $(CFLAGS) ./src/main.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

Game.o: ./src/Game.cpp
	$(CC) $(CFLAGS) ./src/Game.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

Game-Board.o: ./src/Game-Board.cpp
	$(CC) $(CFLAGS) ./src/Game-Board.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)
Cell.o: ./src/Cell.cpp
	$(CC) $(CFLAGS) ./src/Cell.cpp $(SDL-I) $(SDL-F) $(SDL-IMAGE-I) $(SDL-IMAGE-F)

Config: 
	make clean
	make

move:
	mv *.o ./obj

clean: 
	rm -rf ./obj/*o Game-of-Life
