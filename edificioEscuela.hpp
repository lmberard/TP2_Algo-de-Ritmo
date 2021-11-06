#ifndef EDIFICIOESCUELA_HPP
#define EDIFICIOESCUELA_HPP
#include "edificio.hpp"

class Escuela : public Edificio
{

public:
    // PRE:
    // POS:
    Escuela(int s, int w, int m, int p);

    Escuela(Edificio *edificio);

    // PRE:
    // POS:
    ~Escuela();
};
#endif // EDIFICIOESCUELA_HPP
