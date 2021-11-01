#include "edificioObelisco.hpp"

EdificioObelisco::EdificioObelisco(string n, int s, int w, int m, int p) : Edificio(n, s, w, m, p)
{

    this->cant_mat_que_produce = OBELISCO_CANT_MATERIAL_PROD;
    this->mat_que_produce = OBELISCO_MATERIAL_PROD;
}
EdificioObelisco::~EdificioObelisco()
{
}