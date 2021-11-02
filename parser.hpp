#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "lista.hpp"
#include "material.hpp"
#include "edificio.hpp"
#include "edificioAserradero.hpp"
#include "edificioEscuela.hpp"
#include "edificioFabrica.hpp"
#include "edificioMina.hpp"
#include "edificioPlantaElectrica.hpp"
#include "edificioObelisco.hpp"
#include "ubicaciones.hpp"

using namespace std;

const string PATH_MATERIALES = "materiales.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const string PATH_UBICACIONES = "ubicaciones.txt";

class Parser
{

public:
    // PRE:
    // POS:
    void cargar(Lista<Edificio> &edificios);

    // PRE:
    // POS:
    void cargar(Lista<Material> &materiales);

    void cargar(Lista<Ubicacion> &ubicaciones);
};

#endif // PARSER_HPP