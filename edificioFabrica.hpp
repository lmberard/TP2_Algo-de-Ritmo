#ifndef EDIFICIOFABRICA_HPP
#define EDIFICIOFABRICA_HPP
#include "edificio.hpp"

const int FABRICA_CANT_MATERIAL_PROD = 40;
const string FABRICA_MATERIAL_PROD = "metal";

class EdificioFabrica : public Edificio
{
public:
    // PRE:
    // POS:
    EdificioFabrica(string n, int s, int w, int m, int p);

    // PRE:
    // POS:
    ~EdificioFabrica();
};

#endif // EDIFICIOFABRICA_HPP