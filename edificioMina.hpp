#ifndef EDIFICIOMINA_HPP
#define EDIFICIOMINA_HPP
#include "edificio.hpp"

class Mina : public Edificio
{
public:
    // PRE:
    // POS:
    Mina(int s, int w, int m, int p);
    Mina(Edificio *edificio);

    // PRE:
    // POS:
    ~Mina();
};
#endif // EDIFICIOMINA_HPP