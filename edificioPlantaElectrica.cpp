#include "edificioPlantaElectrica.hpp"

EdificioPlantaElectrica::EdificioPlantaElectrica(string n, int s, int w, int m, int p) : Edificio(n, s, w, m, p)
{
    this->cant_mat_que_produce = PLANTA_ELECTRICA_CANT_MATERIAL_PROD;
    this->mat_que_produce = PLANTA_ELECTRICA_MATERIAL_PROD;
}

EdificioPlantaElectrica::~EdificioPlantaElectrica()
{
}