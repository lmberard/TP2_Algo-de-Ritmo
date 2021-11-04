#include "casillero.hpp"

Casillero::Casillero(int x, int y) : coord_x(x), coord_y(y)
{
}
void Casillero::agregar(Edificio *)
{
    cout << "No puedes construir en este casillero" << endl;
}

Casillero::~Casillero()
{
}
