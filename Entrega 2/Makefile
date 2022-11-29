#########################################
CC=gcc
CFLAGS= -g -Wall -pedantic -ansi
#########################################
.PHONY: clean

all: ProyectoI Set_test Die_test

run_project: ProyectoI
	@./ProyectoI data.dat

run_project_log: ProyectoI
	@./ProyectoI data.dat -l LOG.log

run_set_test: Set_test
	@./Set_test

run_die_test: Die_test
	@./Die_test

ProyectoI: command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o set.o die.o
	$(CC) -o ProyectoI command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o set.o die.o

Set_test: set_test.o set.o
	$(CC) -o Set_test set_test.o set.o

Die_test: die_test.o die.o
	$(CC) -o Die_test die_test.o die.o

command.o: command.c command.h
	$(CC) $(CFLAGS) -c command.c

game.o: game.c game.h command.h space.h object.h player.h types.h
	$(CC) $(CFLAGS) -c game.c

game_loop.o: game_loop.c command.h graphic_engine.h game.h game_reader.h screen.h space.h object.h player.h types.h
	$(CC) $(CFLAGS) -c game_loop.c

graphic_engine.o: graphic_engine.c graphic_engine.h screen.h game.h space.h object.h player.h types.h
	$(CC) $(CFLAGS) -c graphic_engine.c

screen.o: screen.c screen.h
	$(CC) $(CFLAGS) -c screen.c

space.o: space.c space.h types.h
	$(CC) $(CFLAGS) -c space.c

game_reader.o: game_reader.c game_reader.h game.h command.h space.h object.h player.h types.h
	$(CC) $(CFLAGS) -c game_reader.c

object.o: object.c object.h types.h
	$(CC) $(CFLAGS) -c object.c

player.o: player.c player.h types.h
	$(CC) $(CFLAGS) -c player.c

set.o: set.c set.h types.h
	$(CC) $(CFLAGS) -c set.c

die.o: die.c die.h types.h
	$(CC) $(CFLAGS) -c die.c

set_test.o: set_test.c set.h types.h
	$(CC) $(CFLAGS) -c set_test.c

die_test.o: die_test.c die.h types.h
	$(CC) $(CFLAGS) -c die_test.c

clean:
	@echo "Cleaning:"
	@rm -rf *.o
