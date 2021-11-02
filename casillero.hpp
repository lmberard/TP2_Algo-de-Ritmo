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
    // PRE:
    // POS:
    Casillero(int x, int y);

    // PRE:
    // POS:
    virtual ~Casillero(){};

    // PRE:
    // POS:
    virtual void mostrar() = 0;

    // PRE:
    // POS:
    virtual void display() = 0;

    // PRE:
    // POS:
    virtual void agregar(Edificio *);
};

#endif // CASILLERO_HPP