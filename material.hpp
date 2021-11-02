#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"

using namespace std;

class Material
{
private:
    string nombre;
    int cantidad;
    // string nombre = "Madera";
    // int cantidad = 50;

public:
    // PRE:
    // POS:
    Material(string nombre, int cant);

    // PRE:
    // POS:
    ~Material();

    // PRE:
    // POS:
    string obtener_nombre();

    // PRE:
    // POS:
    int obtener_cantidad();

    // PRE:
    // POS:
    void modificar_cantidad(int cantidad);

    // PRE:
    // POS:
    void mostrar_material();
};

#endif // MATERIAL_HPP
