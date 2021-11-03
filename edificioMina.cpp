#include "edificioMina.hpp"
#include "edificio.hpp"
Mina::Mina(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "Mina";
    codigo = "M";
    cant_mat_que_produce = MINA_CANT_MATERIAL_PROD;
    mat_que_produce = MINA_MATERIAL_PROD;
}

Mina::Mina(Edificio *edificio): Edificio(edificio){
    nombre = "Mina";
    codigo = "M";
    cant_mat_que_produce = MINA_CANT_MATERIAL_PROD;
    mat_que_produce = MINA_MATERIAL_PROD;
}

Mina::~Mina()
{
}
