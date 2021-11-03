#ifndef EDIFICIOPLANTAELECTRICA_HPP
#define EDIFICIOPLANTAELECTRICA_HPP
#include "edificio.hpp"

const int PLANTA_ELECTRICA_CANT_MATERIAL_PROD = 0;
const string PLANTA_ELECTRICA_MATERIAL_PROD = "No brinda materiales";

class PlantaElectrica : public Edificio
{
public:
    // PRE:
    // POS:
    PlantaElectrica(int s, int w, int m, int p);
    PlantaElectrica(Edificio *edificio);

    // PRE:
    // POS:
    ~PlantaElectrica();
};

#endif // EDIFICIOPLANTAELECTRICA_HPP
