#ifndef CASILLEROS_H
#define CASILLEROS_H

#include <iostream>
#include <string>
#include <fstream>

#include "3_edificios.h"
#include "4_material.h"

using namespace std;

class Casillero{

  protected:
    int coord_x, coord_y;
  
  public:

    Casillero(int coord_x, int coord_y){
      this->coord_x = coord_x;
      this->coord_y = coord_y;
    };
    virtual ~Casillero(){};

    virtual void mostrar() = 0; 
    virtual void display() = 0; 

    virtual void agregar(Edificio*){
     // cout << "No puedes construir en este casillero" << endl;
    };
};

#endif //CASILLEROS




