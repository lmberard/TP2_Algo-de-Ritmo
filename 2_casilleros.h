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

    Casillero(int x, int y):coord_x(x),coord_y(y){};
    virtual ~Casillero(){};

    virtual void mostrar() = 0; 
    virtual void display() = 0; 

    virtual void agregar(Edificio*){
      cout << "No puedes construir en este casillero" << endl;
    };
};

#endif //CASILLEROS




