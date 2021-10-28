#ifndef MAPA_H
#define MAPA_H

#include <iostream>
#include <string>
#include <fstream>
#include "casilleros.h"

class Mapa
{

    int filas;
    int columnas;

    Casillero ***mapa;

public:
    Mapa() : filas(0), columnas(0), mapa(0) {}

    Mapa(const string &);
    ~Mapa();

    void consultar_coordenada(int, int);
    void mostrar_mapa();
};

#endif // MAPA.H