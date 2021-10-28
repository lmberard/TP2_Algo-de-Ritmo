#include <iostream>
#include <string>
#include <fstream>
#include "2_casilleros.h"

using namespace std;

class CasilleroTransitable: public Casillero{

  public:

    CasilleroTransitable(int x, int y): Casillero(x, y){};

    void mostrar()
    { cout << "Soy un casillero transitable y tengo " << " de " << endl;
    cout << "estás en la posición " << coord_x << " " << coord_y << endl;}
    void display(){ cout << " C ";}

    ~CasilleroTransitable(){};
};