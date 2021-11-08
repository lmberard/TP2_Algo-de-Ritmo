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
    virtual bool agregar(Edificio *);

    virtual string obtener_material();
    virtual int obtener_cantidad();

    virtual Edificio* mostrar_edificio();

    virtual void demoler() = 0;
};

#endif // CASILLERO_HPP

    virtual void demoler() = 0;
};

#endif // CASILLERO_HPP