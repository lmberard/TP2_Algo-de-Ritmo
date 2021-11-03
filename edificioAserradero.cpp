
#include "edificio.hpp"
#include "edificioAserradero.hpp"
Aserradero ::Aserradero(int s, int w, int m, int p) : Edificio(s, w, m, p)
{
    nombre = "Aserradero";
    codigo = "A";
    cant_mat_que_produce = ASERRADERO_CANT_MATERIAL_PROD;
    mat_que_produce = ASERRADERO_MATERIAL_PROD;
}

Aserradero::Aserradero(Edificio *edificio): Edificio(edificio){
    nombre = "Aserradero";
    codigo = "A";
    cant_mat_que_produce = ASERRADERO_CANT_MATERIAL_PROD;
    mat_que_produce = ASERRADERO_MATERIAL_PROD;
}

Aserradero ::~Aserradero()
{
}
