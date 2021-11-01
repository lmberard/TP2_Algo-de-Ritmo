#include "edificioAserradero.hpp"
#include "edificio.hpp"
EdificioAserradero ::EdificioAserradero(string n, int s, int w, int m, int p) : Edificio(n, s, w, m, p)
{

    this->cant_mat_que_produce = ASERRADERO_CANT_MATERIAL_PROD;
    this->mat_que_produce = ASERRADERO_MATERIAL_PROD;
}

EdificioAserradero ::~EdificioAserradero()
{
}