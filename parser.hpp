#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "lista.hpp"
#include "material.hpp"
#include "edificio.hpp"

using namespace std;

class Parser
{

public:
    // PRE:
    // POS:
    void cargar(Lista<Edificio> &edificios, const string &PATH);

    // PRE:
    // POS:
    void cargar(Lista<Material> &materiales, const string &PATH);
};

#endif // PARSER_HPP