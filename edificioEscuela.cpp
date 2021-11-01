#include "edificioEscuela.hpp"
#include "edificio.hpp"
EdificioEscuela::EdificioEscuela(string n, int s, int w, int m, int p) : Edificio(n, s, w, m, p)
{

    this->cant_mat_que_produce = ESCUELA_CANT_MATERIAL_PROD;
    this->mat_que_produce = ESCUELA_MATERIAL_PROD;
}

EdificioEscuela::~EdificioEscuela()
{
}