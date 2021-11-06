#include "material.hpp"
#include <string>

using namespace std;

Material::Material(){}

Material::~Material(){}

string Material::obtener_nombre()
{
    return nombre;
}
