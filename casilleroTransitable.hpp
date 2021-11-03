#ifndef CASILLEROTRANSITABLE_HPP
#define CASILLEROTRANSITABLE_HPP
#include "casillero.hpp"

class CasilleroTransitable : public Casillero
{
    Material *material = 0;

public:
    // PRE: -
    // POS: se crea un casilleroTransitable en las coordenadas (x,y)
    CasilleroTransitable(int x, int y);

    // PRE: -
    // POS: se destruye el casillero
    ~CasilleroTransitable();

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    void mostrar();

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    void display();

    // LLUVIA DE RECURSOS------------------------------
    // PRE: -
    // POS: Se agrega un material en el casillero
    void agregar_material(string nombre, int cantidad);
};

#endif // CASILLEROTRANSITABLE_HPP
