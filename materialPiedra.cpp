#include "materialPiedra.hpp"
#include <string>

using namespace std;

Piedra::Piedra(int cant) : Material(cant)
{
    nombre = "Piedra";
    cantidad = cant;
    codigo = "S";
}

Piedra::~Piedra()
{
}
