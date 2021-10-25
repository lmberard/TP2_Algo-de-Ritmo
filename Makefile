PROGRAM=tp1
CC := g++
FLAGS := -Wall -Werror -Wconversion -pedantic -g
LDLFLAGS=-lm
GREEN= \e[92m
NORMAL= \e[0m

all: andypolis

archivos.o: archivos.cpp archivos.h colors.h
	$(CC) $(FLAGS) archivos.o

colors.o: colors.cpp colors.h
	$(CC) $(FLAGS) colors.o

edificios.o: edificios.cpp edificios.h menu.h colors.h
	$(CC) $(FLAGS) edificios.o

menu.o: menu.cpp menu.h colors.h
	$(CC) $(FLAGS) menu.o

andypolis: archivos.cpp menu.cpp edificios.cpp main.cpp colors.cpp
	$(CC) $(FLAGS) $^ -o andypolis

clean:
	rm -vf *.o $(PROGRAM)

gdb: andypolis
	gdb ./andypolis

valgrind: andypolis
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./andypolis