#ifndef EDIFICIOOBELISCO_HPP
#define EDIFICIOOBELISCO_HPP
#include "edificio.hpp"

const int OBELISCO_CANT_MATERIAL_PROD = 0;
const string OBELISCO_MATERIAL_PROD = "No brinda materiales";

class Obelisco : public Edificio
{
public:
    // PRE:
    // POS:
    Obelisco(int s, int w, int m, int p);

    // PRE:
    // POS:
    ~Obelisco();
};

#endif // EDIFICIOOBELISCO_HPP
