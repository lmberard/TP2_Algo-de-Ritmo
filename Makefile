PROGRAM=tp1
CC := g++
FLAGS := -Wall -Werror -Wconversion -pedantic -g
LDLFLAGS=-lm
GREEN= \e[92m
NORMAL= \e[0m

all: andypolis

colors.o: colors.cpp colors.h
	$(CC) $(FLAGS) colors.o

menu.o: menu.cpp menu.h colors.h
	$(CC) $(FLAGS) menu.o

andypolis: menu.cpp main.cpp colors.cpp 
	$(CC) $(FLAGS) $^ -o andypolis

clean:
	rm -vf *.o $(PROGRAM)

gdb: andypolis
	gdb ./andypolis

valgrind: andypolis
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./andypolis