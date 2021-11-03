#include "edificioYacimiento.hpp"

Yacimiento::Yacimiento(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "Yacimiento";
    codigo = "P";
    cant_mat_que_produce = YACIMIENTO_CANT_MATERIAL_PROD;
    mat_que_produce = YACIMIENTO_MATERIAL_PROD;
}

Yacimiento::Yacimiento(Edificio *edificio): Edificio(edificio){
    nombre = "Yacimiento";
    codigo = "Y";
    cant_mat_que_produce = YACIMIENTO_CANT_MATERIAL_PROD;
    mat_que_produce = YACIMIENTO_MATERIAL_PROD;
}

Yacimiento::~Yacimiento()
{
}