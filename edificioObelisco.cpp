#include "edificioObelisco.hpp"

Obelisco::Obelisco(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "obelisco";
    codigo = "O";
    cant_mat_que_produce = 0;
    mat_que_produce = "No produce materiales";
}

Obelisco::Obelisco(Edificio *edificio): Edificio(edificio){}

Obelisco::~Obelisco(){}
