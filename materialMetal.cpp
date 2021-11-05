#include "materialMetal.hpp"
#include <string>

using namespace std;

Metal::Metal(int cant) : Material(cant)
{
    nombre = "Metal";
    cantidad = cant;
    codigo = "M";
}

Metal::~Metal()
{
}
