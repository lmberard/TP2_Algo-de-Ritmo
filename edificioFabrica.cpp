#include "edificioFabrica.hpp"
#include "edificio.hpp"

Fabrica::Fabrica(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "fabrica";
    codigo = "F";
    cant_mat_que_produce = 40;
    mat_que_produce = "metal";
}

Fabrica::Fabrica(Edificio *edificio): Edificio(edificio){}

Fabrica::~Fabrica(){}
