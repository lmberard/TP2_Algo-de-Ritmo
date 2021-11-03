#ifndef EDIFICIOYACIMIENTO_HPP
#define EDIFICIOYACIMIENTO_HPP
#include "edificio.hpp"

const int YACIMIENTO_CANT_MATERIAL_PROD = 0;
const string YACIMIENTO_MATERIAL_PROD = "No brinda materiales";

class Yacimiento : public Edificio
{
public:
    // PRE:
    // POS:
    Yacimiento(int s, int w, int m, int p);
    Yacimiento(Edificio *edificio);

    // PRE:
    // POS:
    ~Yacimiento();
};

#endif // EDIFICIOPLANTAELECTRICA_HPP
