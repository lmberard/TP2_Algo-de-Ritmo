#include <iostream>
#include <string>
#include <fstream>
#include "1_mapa.h"
#include "parser.h"


using namespace std;

int main (){
    Mapa andypolis("mapa.txt");

    Parser parser;

    Lista<Edificio> edificios;
    parser.cargar(edificios,"edificios.txt");

    /*ESTO FALTARIA*/
    //parser.cargar_ubicaciones(edificios,"ubicaciones.txt");

    Lista<Material> materiales;
    parser.cargar(materiales,"materiales.txt");

  

    Edificio* edificio1 = edificios.consulta(1);
    Edificio* edificio2 = edificios.consulta(2);

    cout << edificio1->mostrar() << endl;
    cout << edificio2->mostrar() << endl;


    Material* material1 = materiales.consulta(1);
    Material* material2 = materiales.consulta(2);

    cout << materiales.consulta(2)->mostrar() << endl;

    cout << material1->mostrar() << endl;
    cout << material2->mostrar() << endl;


    andypolis.agregar_edificio(0,3,edificios.consulta(1));
    andypolis.consultar_coordenada(0,3);

  return 0;
}



