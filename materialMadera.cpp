#include "materialMadera.hpp"
#include <string>

using namespace std;

Madera::Madera(int cant) : Material(cant)
{
    nombre = "Madera";
    cantidad = cant;
    codigo = "W";
}

Madera::~Madera()
{
}
