#include <iostream>
#include <string>
#include <fstream>
#include "menu.hpp"
#include "mapa.hpp"
#include "material.hpp"
#include "lista.hpp"
#include "parser.hpp"
#include "ciudad.hpp"

using namespace std;

int main()
{

    Ciudad andypolis;
    andypolis.procesar_archivos();
    //andypolis.cargar_ubicaciones();
    
    
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
