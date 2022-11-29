# Macros.
CC=gcc -g -Wall -ansi -pedantic

# Rules.
all: ocabas

ocabas: space.o game.o command.o graphic_engine.o screen.o game_loop.o
	@echo "Linking..."
	$(CC) -o Ocabas space.o game.o command.o graphic_engine.o screen.o game_loop.o

space.o: space.c space.h types.h
	$(CC) -c space.c

game.o: game.c game.h command.h space.h types.h
	$(CC) -c game.c

command.o: command.c command.h
	$(CC) -c command.c

graphic_engine.o: graphic_engine.c graphic_engine.h screen.h game.h command.h space.h types.h
	$(CC) -c graphic_engine.c

screen.o: screen.c screen.h
	$(CC) -c screen.c

game_loop.o: game_loop.c graphic_engine.h screen.h game.h command.h space.h types.h
	$(CC) -c game_loop.c

clean:
	@echo "Cleaning..."
	@rm -f *.o
	@rm -f Ocabas
