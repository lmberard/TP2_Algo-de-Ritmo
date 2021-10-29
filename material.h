#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <string>
#include <fstream>
#include "colors.h"

using namespace std;

class Material
{
private:
    // string nombre;
    // int cantidad;
    string nombre = "Madera";
    int cantidad = 50;

public:
    // Material(string name, int cantidad);

    //~Material();

    string mostrar_nombre();

    int mostrar_cantidad();

    void modificar_cantidad(int cantidad);

    void mostrar_material();
};

#endif // MATERIAL.H
