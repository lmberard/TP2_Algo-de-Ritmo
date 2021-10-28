#include <iostream>
#include <string>
#include <fstream>
#include "2_casilleros.h"

using namespace std;


class CasilleroConstruible: public Casillero {

    Edificio* edificio = 0;

    public:
        virtual void agregar(Edificio* edificio){
            this->edificio = edificio;
        };

        CasilleroConstruible(int x, int y): Casillero( x, y){};

        void mostrar()
        {cout << "Soy un casillero construible" << endl;
        cout << "estás en la posición " << coord_x << " " << coord_y << endl;
        /*cout << edificio->mostrar() << endl;*/}
        void display(){ cout << " T ";}

       ~CasilleroConstruible(){};
};