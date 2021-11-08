#include <iostream>
#include <string>
#include <fstream>

#include "ciudad.hpp"

using namespace std;

int main(){

    Terreno terreno;
    Constructor bob("edificios.txt");
    Recurso recurso;

    Ciudad andypolis("mapa.txt","materiales.txt","ubicaciones.txt",terreno,bob,recurso);
    
    andypolis.mostrar_mapa();
    andypolis.consultar_coordenada(3,4);
    andypolis.chequear_permisos_edificio("aserradero",bob);
    andypolis.construir(0,3,"aserradero",bob);

    andypolis.construir(8,10,"aserradero",bob);
    andypolis.demoler_edificio(10,10);
    andypolis.mostrar_ubicaciones();
    andypolis.mostrar_mapa();
    andypolis.mostrar_inventario();
    andypolis.recolectar();
    andypolis.mostrar_inventario();
    andypolis.listar_edificios(bob);
    
    return 0;
}
