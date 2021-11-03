#include "edificioObelisco.hpp"

Obelisco::Obelisco(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "Obelisco";
    codigo = "O";
    cant_mat_que_produce = OBELISCO_CANT_MATERIAL_PROD;
    mat_que_produce = OBELISCO_MATERIAL_PROD;
}

Obelisco::Obelisco(Edificio *edificio): Edificio(edificio){
    nombre = "Obelisco";
    codigo = "O";
    cant_mat_que_produce = OBELISCO_CANT_MATERIAL_PROD;
    mat_que_produce = OBELISCO_MATERIAL_PROD;
}

Obelisco::~Obelisco()
{
}
