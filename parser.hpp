#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "lista.hpp"
#include "material.hpp"
#include "mapa.hpp"
#include "edificio.hpp"

#include "edificioAserradero.hpp"
#include "edificioEscuela.hpp"
#include "edificioYacimiento.hpp"
#include "edificioObelisco.hpp"
#include "edificioMina.hpp"
#include "edificioFabrica.hpp"
#include "edificioPlantaElectrica.hpp"


using namespace std;

class Parser
{
 

public:
    // PRE:
    // POS:
    void cargar(Lista<Edificio*> &edificios, const string &PATH);

    // PRE:
    // POS:
    //void cargar(Lista<Material*> &materiales, const string &PATH);
    //void mostrar(const string &PATH);

  void borrar(Lista<Edificio*> & edificios);

};

#endif // PARSER_HPP
