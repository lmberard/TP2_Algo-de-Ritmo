#include <iostream>
#include <string>
#include <fstream>
#include "1_mapa.h"

using namespace std;

int main (){

  Aserradero aserradero;

  Mapa andypolis("mapa.txt");

  andypolis.agregar_edificio(0,0,&aserradero);

  andypolis.consultar_coordenada(0,3);

  //andypolis.mostrar_mapa();

  return 0;
}

