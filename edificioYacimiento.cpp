#include "edificioYacimiento.hpp"

Yacimiento::Yacimiento(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "yacimiento";
    codigo = "Y";
    cant_mat_que_produce = 0;
    mat_que_produce = "No brinda materiales";
}

Yacimiento::Yacimiento(Edificio *edificio): Edificio(edificio){}

Yacimiento::~Yacimiento(){}