#include "material.h"
#include <string>

using namespace std;

/*
Material::Material(string nombre, int cantidad)
{
    this->nombre = nombre;
    this->cantidad = cantidad;
}

Material::~Material()
{
}*/

string Material::mostrar_nombre()
{
    return this->nombre;
}

int Material::mostrar_cantidad()
{
    return this->cantidad;
}

void Material::modificar_cantidad(int cantidad)
{
    this->cantidad += cantidad;
}

void Material::mostrar_material()
{
    cout << "Tipo de Material:" << this->nombre << "\nCantidad:" << to_string(this->cantidad) << endl;
}