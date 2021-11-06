#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"

using namespace std;

class Material
{
protected:
    string nombre;
    string codigo;

public:
    // PRE:
    // POS:
    Material();

    // PRE:
    // POS:
    ~Material();

    // PRE:
    // POS:
    string obtener_nombre();
};

#endif // MATERIAL_HPP