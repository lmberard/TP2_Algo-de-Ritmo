#ifndef EDIFICIOASERRADERO_HPP
#define EDIFICIOASERRADERO_HPP
#include "edificio.hpp"

class Aserradero : public Edificio
{

public:
    // PRE:
    // POS:
    Aserradero(int s, int w, int m, int p);

    Aserradero(Edificio *edificio);

    // PRE:
    // POS:
    ~Aserradero();
};
#endif // EDIFICIOASERRADERO_HPP
