#ifndef EDIFICIOMINA_HPP
#define EDIFICIOMINA_HPP
#include "edificio.hpp"

const int MINA_CANT_MATERIAL_PROD = 15;
const string MINA_MATERIAL_PROD = "piedra";

class EdificioMina : public Edificio
{
public:
    // PRE:
    // POS:
    EdificioMina(string n, int s, int w, int m, int p);

    // PRE:
    // POS:
    ~EdificioMina();
};
#endif // EDIFICIOMINA_HPP