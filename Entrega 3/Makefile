#########################################
CC=gcc
CFLAGS= -g -Wall -pedantic -ansi -I./src. -I./include.
#########################################
.PHONY: clean

all:
	mkdir -p ./obj.
	@make ProyectoI
	@make Set_test
	@make Die_test
	@make Inventory_test
	@make Link_test
	@make Object_test
	@make Space_test
	@make Doxygen
	@make compress

run_project:
	@mkdir -p ./obj.
	@make ProyectoI
	@./ProyectoI data.dat

run_project_log:
	@mkdir -p ./obj.
	@make ProyectoI
	@./ProyectoI data.dat -l LOG.log

run_set_test:
	@mkdir -p ./obj.
	@make Set_test
	@./Set_test

run_die_test:
	@mkdir -p ./obj.
	@make Die_test
	@./Die_test

run_inventory_test:
	@mkdir -p ./obj.
	@make Inventory_test
	@./Inventory_test

run_link_test:
	@mkdir -p ./obj.
	@make Link_test
	@./Link_test

run_object_test:
	@mkdir -p ./obj.
	@make Object_test
	@./Object_test

run_space_test:
	@mkdir -p ./obj.
	@make Space_test
	@./Space_test

compress:
	@mkdir -p ./obj.
	@make ProyectoI
	@tar -cvzf Iteracion3.tgz ./src./*.c ./include./*.h ./obj./*.o
	@rm -rf ProyectoI

Doxygen:
	@mkdir -p ./doc.
	@cp -r ./src./*.c ./include./*.h ./doc.
	@cd ./doc.; doxygen -g; doxygen Doxyfile; rm -rf *.c; rm -rf *.h;

ProyectoI: command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o inventory.o link.o set.o die.o
	$(CC) -o ProyectoI command.o game.o game_loop.o graphic_engine.o screen.o space.o game_reader.o object.o player.o inventory.o link.o set.o die.o
	mv *.o ./obj.

Set_test: set_test.o set.o
	$(CC) -o Set_test set_test.o set.o
	mv *.o ./obj.

Die_test: die_test.o die.o
	$(CC) -o Die_test die_test.o die.o
	mv *.o ./obj.

Inventory_test: inventory_test.o inventory.o set.o
	$(CC) -o Inventory_test inventory_test.o inventory.o set.o
	mv *.o ./obj.

Link_test: link_test.o link.o
	$(CC) -o Link_test link_test.o link.o
	mv *.o ./obj.

Object_test: object_test.o object.o set.o
	$(CC) -o Object_test object_test.o object.o set.o
	mv *.o ./obj.

Space_test: space_test.o space.o set.o
	$(CC) -o Space_test space_test.o space.o set.o
	mv *.o ./obj.


command.o: ./src./command.c ./include./command.h
	$(CC) $(CFLAGS) -c ./src./command.c

game.o: ./src./game.c ./include./game.h ./include./command.h ./include./space.h ./include./object.h ./include./player.h ./include./die.h ./include./link.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./game.c

game_loop.o: ./src./game_loop.c ./include./command.h ./include./graphic_engine.h ./include./game.h ./include./game_reader.h ./include./screen.h ./include./space.h ./include./object.h ./include./player.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./game_loop.c

graphic_engine.o: ./src./graphic_engine.c ./include./graphic_engine.h ./include./screen.h ./include./game.h ./include./space.h ./include./object.h ./include./player.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./graphic_engine.c

screen.o: ./src./screen.c ./include./screen.h
	$(CC) $(CFLAGS) -c ./src./screen.c

space.o: ./src./space.c ./include./space.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./space.c

game_reader.o: ./src./game_reader.c ./include./game_reader.h ./include./game.h ./include./command.h ./include./space.h ./include./object.h ./include./player.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./game_reader.c

object.o: ./src./object.c ./include./object.h ./include./set.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./object.c

player.o: ./src./player.c ./include./player.h ./include./inventory.h ./include./set.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./player.c

inventory.o: ./src./inventory.c ./include./inventory.h ./include./set.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./inventory.c

link.o: ./src./link.c ./include./link.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./link.c

set.o: ./src./set.c ./include./set.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./set.c

die.o: ./src./die.c ./include./die.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./die.c

set_test.o: ./src./set_test.c ./include./set.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./set_test.c

die_test.o: ./src./die_test.c ./include./die.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./die_test.c

inventory_test.o: ./src./inventory_test.c ./include./inventory_test.h ./include./inventory.h ./include./set.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./inventory_test.c

link_test.o: ./src./link_test.c ./include./link_test.h ./include./link.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./link_test.c

object_test.o: ./src./object_test.c ./include./object_test.h ./include./object.h ./include./set.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./object_test.c

space_test.o: ./src./space_test.c ./include./space_test.h ./include./space.h ./include./set.h ./include./types.h
	$(CC) $(CFLAGS) -c ./src./space_test.c

clean:
	@echo "Cleaning:"
	@rm -rf ./doc.
	@rm -rf ./obj.
	@rm -rf ProyectoI
	@rm -rf *_test
	@rm -rf *.log
	@rm -rf *.tgz
