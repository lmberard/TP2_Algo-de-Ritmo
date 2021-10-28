#include "menu.h"
//#include "edificios.h"
//#include "archivos.h"

using namespace std;

int main()
{
    string rta = " ";
    do
    {
        mostrar_InstruccionInicial();
        rta = devolver_rta_usuario();
        if (rta == "si")
        {
            mostrar_menuInicial();
            return 0;
        }
        else
            msjeError("Error. Opciones validas: 'si' o 'no'");
    } while (rta != "no");

    msjeInstruccion("Hasta luego!! :)");
    return 0;
}