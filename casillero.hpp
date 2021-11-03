#ifndef CASILLERO_HPP
#define CASILLERO_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"
#include "material.hpp"
#include "edificio.hpp"

using namespace std;

class Casillero
{

protected:
    int coord_x = 0;
    int coord_y = 0;

public:
    // PRE: -
    // POS: se crea un casillero con las coordenadas (x,y)
    Casillero(int x, int y);

    // PRE: -
    // POS: se destruye el casillero
    virtual ~Casillero(){};

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    virtual void mostrar() = 0;

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    virtual void display() = 0;

    // LLUVIA DE RECURSOS -----------------------------------------
    // PRE: -
    // POS: agrega un material en el casillero (casilleroTransitable)
    virtual void agregar_material(string nombre, int cantidad);

    // RECOLECTAR MATERIALES --------------------------------------
    // PRE: -
    // POS: devuelve el material que construye (casilleroConstruible)
    virtual string devolver_material_produccion();

    // PRE: -
    // POS: devuelve la cantidad del material que construye (casilleroConstruible)
    virtual int devolver_cant_material_produccion();

    // CONSTRUIR / DESTRUIR EDIFICIO ------------------------------
    // PRE: -
    // POS: agrega un edificio en el casillero (casilleroConstruible)
    virtual void construir_edificio(string nombre);

    // PRE: -
    // POS: se destruye el edificio del casillero (casilleroConstruible)
    virtual void destruir_edificio();
};

#endif // CASILLERO_HPP