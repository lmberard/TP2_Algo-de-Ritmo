#include "menu.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "edificios.h"
#include "archivos.h"
#include "colors.h"

using namespace std;

void mostrar_InstruccionInicial()
{
    cout << TXT_BOLD << TXT_RED_196 << "RECORDATORIO" << END_COLOR << endl;
    cout << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "Para ver el menu de Andypolis se necesitan los siguientes archivos:" << END_COLOR << endl;
    msjeInstruccion("\t-> materiales.txt\n\t-> edificios.txt\n\t->mapa.txt\n\t->ubicaciones.txt\n");
    cout << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "El formato de los mismos es el siguiente:" << END_COLOR << endl;
    msjeInstruccion("\t-> materiales.txt:\n\tmaterial cantidad\n\n\t->edificios.txt:\n\tnombre madera metal piedra cant_construidos max_cant_permitidos\n");
    cout << TXT_BOLD << TXT_LIGHT_BLUE_6 << "Estan separados por un espacio ' '" << END_COLOR << endl;
}

void mostrar_menu()
{
    cout << " " << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "¡¡Bienvenido a Andypolis!! ¿Que desea hacer hoy?" << END_COLOR << " " << endl;
    cout << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╔══════════════════════════════════════════════╗" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 1. Construir edificio por nombre.            ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 2. Listar los edificios construidos.         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 3. Listar todos los edificios.               ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 4. Demoler un edificio por coordenada.       ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 5. Mostrar mapa.                             ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 6. Consultar coordenada.                     ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 7. Mostrar inventario.                       ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 8. Recolectar recursos producidos            ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 9. Lluvia de recursos.                       ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 10. Guardar y salir.                         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╚══════════════════════════════════════════════╝" << endl;
    cout << END_COLOR;
    cout << endl;
    msjeInstruccion("Ingrese la opcion con un NUMERO del 1 al 10:");
}

string devolver_respuesta()
{
    string rta = " ";
    cout << TXT_BOLD << TXT_RED_196 << "En caso de no tener esos formatos, los resultados no seran los correctos" << END_COLOR << endl;
    cout << TXT_BOLD << TXT_LIGHT_BLUE_6 << "\n¿Desea continuar? (SI/NO) " << END_COLOR << endl;
    cin >> rta;
    transform(rta.begin(), rta.end(), rta.begin(), ::tolower);
    return rta;
}

void validar_opcion(int opcion_elegida)
{
    while (!es_opcion_valida(opcion_elegida))
    {
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(100, '\n');
            msjeError("Se tiene que ingresar un numero entero del 1 al 6.\nIntentemos de nuevo:");
            mostrar_menu();
            cin >> opcion_elegida;
        }
        cin.clear();
        cin.ignore(100, '\n');
        msjeError("Ese numero de opcion no es valido, intentemos otra vez:");
        mostrar_menu();
        cin >> opcion_elegida;
    }
}

void volver()
{
    msjeInstruccion("\nPresiona ENTER para volver al menu..");
    cin.get();

    cin.get();
    system(CLR_SCREEN);
}

void procesar_opcion(int opcion_elegida, material_t materiales_array[MAX], edificio_t edificios_array[MAX])
{
    switch (opcion_elegida)
    {
    case CONSTRUIR_EDIFICIO:
        // construir_edificio(edificios_array, materiales_array);
        break;

    case LISTAR_CONSTRUIDOS:
        //
        break;

    case LISTAR_TODOS:
        listar_todos_edificios(edificios_array);
        break;

    case DEMOLER_POR_COORDENADA:
        // demoler_edificio(edificios_array, materiales_array);
        break;

    case MOSTRAR_MAPA:
        // mostrar_mapa();
        break;

    case CONSULTAR_COORDENADA:
        // consultar_coordenada();
        break;

    case MOSTRAR_INVENTARIO:
        // mostrar_inventario();
        break;

    case RECOLECTAR_RECURSOS:
        // recolectar_recursos();
        break;

    case LLUVIA_RECURSOS:
        // lluvia_recursos();
        break;

    case SALIR:
        guardar_archivos(edificios_array, materiales_array);
        break;

    default:
        msjeError("Error: opcion invalida");
    }
}

bool es_opcion_valida(int elegida)
{
    return (elegida >= OPCION_MINIMA && elegida <= OPCION_MAXIMA);
}
