PROGRAM= andypolis
CC:= g++
FLAGS:= -Wall -Werror -Wconversion -pedantic -g
LDLFLAGS= -lm

all: andypolis

colors.o: colors.cpp colors.hpp
	$(CC) $(FLAGS) colors.o

material.o: material.cpp material.hpp 
	$(CC) $(FLAGS) material.o

edificio.o: material.hpp edificio.hpp edificio.cpp edificioAserradero.cpp edificioEscuela.cpp edificioFabrica.cpp edificioMina.cpp edificioObelisco.cpp edificioPlantaElectrica.cpp
	$(CC) $(FLAGS) edificio.o

casillero.o: edificio.hpp material.hpp casillero.hpp casillero.cpp casilleroConstruible.cpp casilleroInaccesible.cpp casilleroTransitable.cpp 
	$(CC) $(FLAGS) casillero.o

mapa.o: casillero.hpp edificio.hpp material.hpp mapa.hpp mapa.cpp lista.hpp nodo.hpp
	$(CC) $(FLAGS) mapa.o

menu.o: casillero.hpp edificio.hpp material.hpp mapa.hpp menu.cpp menu.hpp
	$(CC) $(FLAGS) menu.o

parser.o: parser.hpp parser.cpp lista.hpp nodo.hpp
	$(CC) $(FLAGS) parser.o

andypolis: ciudad.cpp ciudad.hpp casillero.hpp edificio.hpp material.hpp mapa.hpp main.cpp parser.cpp colors.cpp casillero.cpp casilleroConstruible.cpp casilleroInaccesible.cpp casilleroTransitable.cpp mapa.cpp material.cpp materialMadera.cpp materialPiedra.cpp materialMetal.cpp edificio.cpp edificioAserradero.cpp edificioYacimiento.cpp edificioEscuela.cpp edificioFabrica.cpp edificioMina.cpp edificioObelisco.cpp edificioPlantaElectrica.cpp menu.cpp 
	$(CC) $(FLAGS) $^ -o andypolis

clean:
	rm -vf *.o $(PROGRAM)

gdb: andypolis
	gdb ./andypolis

valgrind: andypolis
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./andypolis