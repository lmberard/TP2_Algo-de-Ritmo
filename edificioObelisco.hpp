#ifndef EDIFICIOOBELISCO_HPP
#define EDIFICIOOBELISCO_HPP
#include "edificio.hpp"

const int OBELISCO_CANT_MATERIAL_PROD = 0;
const string OBELISCO_MATERIAL_PROD = "No brinda materiales";

class EdificioObelisco : public Edificio
{
public:
    // PRE:
    // POS:
    EdificioObelisco(string n, int s, int w, int m, int p);

    // PRE:
    // POS:
    ~EdificioObelisco();
};

#endif // EDIFICIOOBELISCO_HPP