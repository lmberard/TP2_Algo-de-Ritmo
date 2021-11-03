#include "edificioPlantaElectrica.hpp"

PlantaElectrica::PlantaElectrica(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "Planta Eléctrica";
    codigo = "P";
    cant_mat_que_produce = PLANTA_ELECTRICA_CANT_MATERIAL_PROD;
    mat_que_produce = PLANTA_ELECTRICA_MATERIAL_PROD;
}

PlantaElectrica::~PlantaElectrica()
{
}
