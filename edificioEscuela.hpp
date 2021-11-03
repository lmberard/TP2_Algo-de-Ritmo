#ifndef EDIFICIOESCUELA_HPP
#define EDIFICIOESCUELA_HPP
#include "edificio.hpp"

const int ESCUELA_CANT_MATERIAL_PROD = 0;
const string ESCUELA_MATERIAL_PROD = "No brinda materiales";

class Escuela : public Edificio
{

public:
    // PRE:
    // POS:
    Escuela(int s, int w, int m, int p);

    // PRE:
    // POS:
    ~Escuela();
};
#endif // EDIFICIOESCUELA_HPP
