#ifndef EDIFICIOPLANTAELECTRICA_HPP
#define EDIFICIOPLANTAELECTRICA_HPP
#include "edificio.hpp"

const int PLANTA_ELECTRICA_CANT_MATERIAL_PROD = 0;
const string PLANTA_ELECTRICA_MATERIAL_PROD = "No brinda materiales";

class EdificioPlantaElectrica : public Edificio
{
public:
    // PRE:
    // POS:
    EdificioPlantaElectrica(string n, int s, int w, int m, int p);

    // PRE:
    // POS:
    ~EdificioPlantaElectrica();
};

#endif // EDIFICIOPLANTAELECTRICA_HPP