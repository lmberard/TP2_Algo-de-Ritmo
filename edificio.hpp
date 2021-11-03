#ifndef EDIFICIO_HPP
#define EDIFICIO_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"
//#include "material.hpp"

class Edificio
{

protected:
    string nombre;
    int piedra;
    int madera;
    int metal;
    int cant_max_construccion;

    string mat_que_produce;
    int cant_mat_que_produce;
    string codigo; 

public:
    // PRE:
    // POS:
    Edificio(int s, int w, int m, int p);
    // virtual ~Edificio() = 0;
    Edificio(Edificio* edificio);
    // PRE:
    // POS:
    string obtener_nombre();

    // PRE:
    // POS:
    int obtener_madera();

    // PRE:
    // POS:
    int obtener_metal();

    // PRE:
    // POS:
    int obtener_piedra();

    // PRE:
    // POS:
    int obtener_cant_max();

    // PRE:
    // POS:
    string obtener_codigo();

    // PRE:
    // POS:
    int obtener_cant_mat_producido();

    // PRE:
    // POS:
    string obtener_mat_producido();

    // PRE:
    // POS:
    void mostrar_edificio();

};

#endif // EDIFICIO_HPP
