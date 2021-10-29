#include <iostream>
#include <string>
#include <fstream>
#include "menu.h"
#include "mapa.h"
#include "material.h"

using namespace std;

int main()
{

    /*
    ACA SE CREARIAN LOS VECTORES Y EL MAPA
    */

    Mapa andypolis("mapa.txt");

    string rta = " ";
    do
    {
        mostrar_InstruccionInicial();
        rta = devolver_rta_usuario();
        if (rta == "si")
        {
            mostrar_menuInicial(andypolis);
            return 0;
        }
        else if (rta != "no")
            msjeError("Error. Opciones validas: 'si' o 'no'");
    } while (rta != "no");

    msjeInstruccion("Hasta luego!! :)");
    return 0;
}