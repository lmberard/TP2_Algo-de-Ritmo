#include <iostream>
#include <string>
#include <fstream>

#include "menu.hpp"
#include "ciudad.hpp"

using namespace std;

int main(){

    Terreno terreno;
    Constructor bob("edificios.txt");
    Recurso recurso;

    Ciudad andypolis("mapa.txt","materiales.txt","ubicaciones.txt",terreno,bob,recurso);
    
    string rta = " ";
    do
    {
        mostrar_InstruccionInicial();
        rta = devolver_rta_usuario();
        if (rta == "si")
        {
            mostrar_menuInicial(andypolis,bob,recurso);
            return 0;
        }
        else if (rta != "no")
            msjeError("Error. Opciones validas: 'si' o 'no'");
    } while (rta != "no");

    msjeInstruccion("Hasta luego!! :)");
    
    return 0;
}