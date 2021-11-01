#ifndef CASILLEROTRANSITABLE_HPP
#define CASILLEROTRANSITABLE_HPP
#include "casillero.hpp"

class CasilleroTransitable : public Casillero
{
    Material *material = 0;

public:
    // PRE:
    // POS:
    CasilleroTransitable(int x, int y);

    // PRE:
    // POS:
    ~CasilleroTransitable();

    // PRE:
    // POS:
    void mostrar();

    // PRE:
    // POS:
    void display();

    // para la funcion de lluvia de materiales:

    /* void agregar_material(string nombre, int cantidad, Ciudad andypolis)
     {

         material = new Material(nombre, cantidad);
         andypolis.agregar_material(nombre, cantidad, material);
     }*/
};

#endif // CASILLEROTRANSITABLE_HPP
