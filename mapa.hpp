#ifndef MAPA_HPP
#define MAPA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "casillero.hpp"
#include "casilleroTransitable.hpp"
#include "casilleroInaccesible.hpp"
#include "casilleroConstruible.hpp"
#include "edificio.hpp"
#include "lista.hpp"
#include "ubicaciones.hpp"

class Mapa
{

    int filas;
    int columnas;

    Casillero ***mapa;
    Ubicacion ubicaciones[80];

public:
    // PRE:
    // POS:
    Mapa();

    // PRE:
    // POS:
    Mapa(const string &);

    // PRE:
    // POS:
    ~Mapa();

    // PRE:
    // POS:
    void consultar_coordenada(int, int);

    // PRE:
    // POS:
    void mostrar_mapa();

    // PRE:
    // POS:
    void agregar_edificio(int, int, Edificio *);


    void cargar_ubicaciones(const string& PATH);

};

#endif // MAPA_HPP
