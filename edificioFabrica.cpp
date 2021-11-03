#include "edificioFabrica.hpp"
#include "edificio.hpp"
Fabrica::Fabrica(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "Fábrica";
    codigo = "F";
    cant_mat_que_produce = FABRICA_CANT_MATERIAL_PROD;
    mat_que_produce = FABRICA_MATERIAL_PROD;
}

Fabrica::Fabrica(Edificio *edificio): Edificio(edificio){
    nombre = "Fabrica";
    codigo = "F";
    cant_mat_que_produce = FABRICA_CANT_MATERIAL_PROD;
    mat_que_produce = FABRICA_MATERIAL_PROD;
}

Fabrica::~Fabrica()
{
}
