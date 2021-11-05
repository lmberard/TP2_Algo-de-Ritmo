#ifndef EDIFICIOOBELISCO_HPP
#define EDIFICIOOBELISCO_HPP
#include "edificio.hpp"

class Obelisco : public Edificio
{
public:
    // PRE:
    // POS:
    Obelisco(int s, int w, int m, int p);

    Obelisco(Edificio *edificio);

    // PRE:
    // POS:
    ~Obelisco();
};

#endif // EDIFICIOOBELISCO_HPP
