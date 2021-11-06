#include <iostream>
#include <string>
#include <fstream>

#include "ciudad.hpp"

using namespace std;

int main(){
    Ciudad andypolis("mapa.txt");
    andypolis.mostrar_mapa();
    andypolis.consultar_coordenada(3,4);
    andypolis.chequear_permisos_edificio("aserradero");
    //andypolis.construir(0,2,"aserradero");
    //andypolis.demoler_edificio(0,2);
    //andypolis.demoler_todo();
    andypolis.mostrar_ubicaciones();
    andypolis.mostrar_mapa();
    

    return 0;
}