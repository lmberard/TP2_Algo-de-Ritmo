#ifndef EDIFICIOASERRADERO_HPP
#define EDIFICIOASERRADERO_HPP
#include "edificio.hpp"

const int ASERRADERO_CANT_MATERIAL_PROD = 25;
const string ASERRADERO_MATERIAL_PROD = "madera";

class Aserradero : public Edificio
{
public:
    // PRE:
    // POS:
    Aserradero(int s, int w, int m, int p);

    // PRE:
    // POS:
    ~Aserradero();
};
#endif // EDIFICIOASERRADERO_HPP
