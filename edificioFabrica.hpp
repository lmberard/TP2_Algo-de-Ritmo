#ifndef EDIFICIOFABRICA_HPP
#define EDIFICIOFABRICA_HPP
#include "edificio.hpp"

const int FABRICA_CANT_MATERIAL_PROD = 40;
const string FABRICA_MATERIAL_PROD = "metal";

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
