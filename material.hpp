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
    int cantidad = 1;

public:
    // PRE:
    // POS:
    Material();

    Material(int );

    // PRE:
    // POS:
    ~Material();

    // PRE:
    // POS:
    string obtener_nombre();

    string obtener_codigo(){
        return codigo;
    }

    int obtener_cantidad(){
        return cantidad;
    }

    void modificar_cantidad(int cantidad){
        this->cantidad = cantidad;
    }
};

#endif // MATERIAL_HPP