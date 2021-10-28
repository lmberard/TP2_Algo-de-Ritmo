#include <iostream>
#include <string>
#include <fstream>
#include "2_casilleros.h"

using namespace std;

class CasilleroInaccesible: public Casillero{
    public:

        CasilleroInaccesible(int x, int y): Casillero(x, y){};
        void mostrar()
        {cout << "Soy un casillero inaccesible y estás en la posición "<< coord_x << " " << coord_y << endl;}
        void display(){ cout << " L ";}

        ~CasilleroInaccesible(){};
};
