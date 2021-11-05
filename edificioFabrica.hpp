#ifndef EDIFICIOFABRICA_HPP
#define EDIFICIOFABRICA_HPP
#include "edificio.hpp"

class Fabrica : public Edificio
{
public:
    // PRE:
    // POS:
    Fabrica(int s, int w, int m, int p);

    Fabrica(Edificio *edificio);

    // PRE:
    // POS:
    ~Fabrica();
};

#endif // EDIFICIOFABRICA_HPP
