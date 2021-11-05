#include "edificioEscuela.hpp"
#include "edificio.hpp"

Escuela::Escuela(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "escuela";
    codigo = "E";
    cant_mat_que_produce = 0;
    mat_que_produce = "No brinda materiales";
}

Escuela::Escuela(Edificio *edificio): Edificio(edificio){  }

Escuela::~Escuela(){}
