#include "material.hpp"
#include <string>

using namespace std;

Material::Material(){}

Material::Material(int cantidad){
    this->cantidad = cantidad;
}

Material::~Material(){}

string Material::obtener_nombre()
{
    return nombre;
}
