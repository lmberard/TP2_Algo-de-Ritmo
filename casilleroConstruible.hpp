#ifndef CASILLEROCONSTRUIBLE_HPP
#define CASILLEROCONSTRUIBLE_HPP
#include "casillero.hpp"

class CasilleroConstruible : public Casillero
{
    Edificio *edificio = 0;

public:
    // PRE:
    // POS:
    CasilleroConstruible();

    // PRE:
    // POS:
    ~CasilleroConstruible();

    // PRE:
    // POS:
    bool agregar(Edificio *edificio);

    // PRE:
    // POS:
    void mostrar();

    // PRE:
    // POS:
    void display();
  
    void demoler(){
        delete edificio;
        edificio = NULL;
    }

    Edificio * mostrar_edificio();
};
#endif // CASILLEROONSTRUIBLE_HPP
