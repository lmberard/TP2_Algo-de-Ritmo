#ifndef EDIFICIOPLANTAELECTRICA_HPP
#define EDIFICIOPLANTAELECTRICA_HPP
#include "edificio.hpp"

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
