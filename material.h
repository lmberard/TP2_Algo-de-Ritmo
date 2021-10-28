#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <string>
#include <fstream>
#include "colors.h"

using namespace std;

class Material
{
    string nombre = "Madera";
    int cantidad = 60;

public:
    string mostrar_nombre()
    {
        return nombre;
    }
    int mostrar_cantidad()
    {
        return cantidad;
    }
};

#endif // MATERIAL.H
