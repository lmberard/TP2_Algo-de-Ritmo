#include "edificioMina.hpp"
#include "edificio.hpp"
EdificioMina::EdificioMina(string n, int s, int w, int m, int p) : Edificio(n, s, w, m, p)
{

    this->cant_mat_que_produce = MINA_CANT_MATERIAL_PROD;
    this->mat_que_produce = MINA_MATERIAL_PROD;
}

EdificioMina::~EdificioMina()
{
}