#ifndef CASILLEROINACCESIBLE_HPP
#define CASILLEROINACCESIBLE_HPP
#include "casillero.hpp"

class CasilleroInaccesible : public Casillero
{
public:
    // PRE:
    // POS:
    CasilleroInaccesible();

    // PRE:
    // POS:
    ~CasilleroInaccesible();

    // PRE:
    // POS:
    void mostrar();

    // PRE:
    // POS:
    void display();

    void demoler(){};
};

#endif // CASILLEROINACCESIBLE_HPP
