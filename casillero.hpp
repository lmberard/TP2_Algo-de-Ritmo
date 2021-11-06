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
public:
    // PRE:
    // POS:
    Casillero();

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

    virtual void demoler() = 0;
};

#endif // CASILLERO_HPP
