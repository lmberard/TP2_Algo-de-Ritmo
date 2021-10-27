#include <iostream>
#include <string>
#include <fstream>
#include "mapa.h"

using namespace std;

int main (){

  Mapa andypolis("mapa.txt");

  andypolis.consultar_coordenada(0,0);

  andypolis.mostrar_mapa();

  return 0;
}