#ifndef MATERIALPIEDRA_HPP
#define MATERIALPIEDRA_HPP
#include "material.hpp"


#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"

using namespace std;

class Piedra : public Material
{

public:
    // PRE:
    // POS:
    Piedra();

    Piedra(int );

    // PRE:
    // POS:
    ~Piedra();
};

#endif // MATERIAL_HPP