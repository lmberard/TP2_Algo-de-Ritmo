#include "edificioPlantaElectrica.hpp"

PlantaElectrica::PlantaElectrica(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "planta electrica";
    codigo = "P";
    cant_mat_que_produce = 0;
    mat_que_produce = "No brinda materiales";
}

PlantaElectrica::PlantaElectrica(Edificio *edificio): Edificio(edificio){}

PlantaElectrica::~PlantaElectrica(){}

