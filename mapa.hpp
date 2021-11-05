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
    // Ubicacion ubicaciones[80];
    Lista<Ubicacion> ubicaciones;

public:
    // PRE:
    // POS:
    Mapa();

    // PRE:
    // POS:
    void cargar(const string &);

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

    void cargar_ubicaciones(const string &PATH);

    void mostrar_ubicaciones();

    void demoler_edificio(int x, int y);

    Ubicacion devolver_ubicacion(int i);

    int cant_edificios();

    string ubicacion_nombre(int i);

    int ubicacion_coord_x(int i);

    int ubicacion_coord_y(int i);
};

#endif // MAPA_HPP
