#ifndef CASILLEROINACCESIBLE_HPP
#define CASILLEROINACCESIBLE_HPP
#include "casillero.hpp"

class CasilleroInaccesible : public Casillero
{
public:
    // PRE: -
    // POS: se crea un casilleroInaccesible en la posicion (x,y)
    CasilleroInaccesible(int x, int y);

    // PRE: -
    // POS: se destruye el casilleroInaccesible
    ~CasilleroInaccesible();

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    void mostrar();

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    void display();
};

#endif // CASILLEROINACCESIBLE_HPP