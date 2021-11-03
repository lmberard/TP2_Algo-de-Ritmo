#include "edificioEscuela.hpp"
#include "edificio.hpp"
Escuela::Escuela(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "Escuela";
    codigo = "E";
    cant_mat_que_produce = ESCUELA_CANT_MATERIAL_PROD;
    mat_que_produce = ESCUELA_MATERIAL_PROD;
}

Escuela::~Escuela()
{
}
