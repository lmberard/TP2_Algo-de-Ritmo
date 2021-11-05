#include "menu.hpp"
#include "casillero.hpp"
#include "mapa.hpp"
#include "parser.hpp"

using namespace std;

 Parser parser;


void mostrar_InstruccionInicial()
{
    cout << TXT_BOLD << TXT_RED_196 << "RECORDATORIO" << END_COLOR << endl;
    cout << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "Para ver el menu de Andypolis se necesitan los siguientes archivos:" << END_COLOR << endl;
    msjeInstruccion("\t-> materiales.txt\n\t-> edificios.txt\n\t-> mapa.txt\n\t-> ubicaciones.txt\n");
    cout << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "El formato de los mismos es el siguiente:" << END_COLOR << endl;
    msjeInstruccion("\t-> materiales.txt:\n\tmaterial cantidad\n\n\t-> edificios.txt:\n\tnombre madera metal piedra max_cant_permitidos\n\n\t-> ubicaciones.txt:\n\tnombre_edificio (coord_x, coord_y)\n\n\t-> mapa.txt:\n\tcant_filas cant_columnas\n\tL T C ... ");
    cout << TXT_BOLD << TXT_RED_196 << "En caso de no tener esos formatos, los resultados no seran los correctos" << END_COLOR << endl;
    cout << TXT_BOLD << TXT_LIGHT_BLUE_6 << "\n¿Desea continuar? (SI/NO) " << END_COLOR << endl;
}

void mostrar_menu()
{
    cout << " " << TXT_BOLD << TXT_UNDERLINE << TXT_LIGHT_BLUE_6 << "¡¡Bienvenido a Andypolis!! ¿Que desea hacer hoy?" << END_COLOR << " " << endl;
    cout << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╔══════════════════════════════════════════════╗" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 1.  Construir edificio por nombre.           ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 2.  Listar los edificios construidos.        ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 3.  Listar todos los edificios.              ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 4.  Demoler un edificio por coordenada.      ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 5.  Mostrar mapa.                            ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 6.  Consultar coordenada.                    ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 7.  Mostrar inventario.                      ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 8.  Recolectar recursos producidos           ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 9.  Lluvia de recursos.                      ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "║ 10. Guardar y salir.                         ║" << END_COLOR << " " << endl;
    cout << "\t" << TXT_LIGHT_PURPLE_141 << "╚══════════════════════════════════════════════╝" << endl;
    cout << END_COLOR;
    cout << endl;
    msjeInstruccion("Ingrese la opcion con un NUMERO del 1 al 10:");
}

string devolver_rta_usuario()
{
    string rta = " ";
    cin >> rta;
    transform(rta.begin(), rta.end(), rta.begin(), ::tolower);
    return rta;
}

void mostrar_menuInicial(Ciudad &andypolis)
{
    system(CLR_SCREEN);
    int opcion_elegida;
    do
    {
        mostrar_menu();
        cin >> opcion_elegida;
        while (!es_opcion_valida(opcion_elegida))
        {
            if (!cin.good())
            {
                cin.clear();
                cin.ignore(100, '\n');
                msjeError("Se tiene que ingresar un numero entero del " + to_string(OPCION_MINIMA) + "al" + to_string(OPCION_MAXIMA) + ".\nIntentemos de nuevo:");
                mostrar_menu();
                cin >> opcion_elegida;
            }
            cin.clear();
            cin.ignore(100, '\n');
            msjeError("Ese numero de opcion no es valido, intentemos otra vez:");
            mostrar_menu();
            cin >> opcion_elegida;
        }
        procesar_opcion(opcion_elegida, andypolis);
    } while (opcion_elegida != SALIR);
}

void validar_opcion(int opcion_elegida)
{
    while (!es_opcion_valida(opcion_elegida))
    {
        if (!cin.good())
        {
            cin.clear();
            cin.ignore(100, '\n');
            msjeError("Se tiene que ingresar un numero entero del" + to_string(OPCION_MINIMA) + "al" + to_string(OPCION_MAXIMA) + "\nIntentemos de nuevo:");
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

void procesar_opcion(int opcion_elegida, Ciudad &andypolis)
{

    switch (opcion_elegida)
    {
  
    case CONSTRUIR_EDIFICIO:
    //De este, falta: todos los mensajes, chequear las validaciones existentes, crear la validacion del casillero
    //subir la direccion del edificio creado a ubicacion. 
       andypolis.construir(1,8,"escuela");
       volver();
        break;

    case LISTAR_CONSTRUIDOS:
        //FALTA HACERLO LINDO Y VALIDAR EN CASO DE NO HABER CONSTRUIDOS
        andypolis.mostrar_ubicaciones();
        volver();
        break;

    case LISTAR_TODOS:
        //FALTA HACERLO LINDO, CREO QUE HAY QUE ASUMIR QUE VIENE TODO BIEN
        andypolis.listar_edificios();
        volver();
        break;

    case DEMOLER_POR_COORDENADA:
        //Faltan todos los mensajes y los chequeos y borrarlo de la lista de ubicaciones
        andypolis.demoler_edificio(3,2);
        volver();
        break;

    case MOSTRAR_MAPA:
        //TERMINADO
        andypolis.mostrar_mapa();
        volver();
        break;

    case CONSULTAR_COORDENADA:
        //FALTAN VARIOS MENSAJES Y CHEQUEOS
        andypolis.consultar_coordenada(0, 3);
        volver();
        break;

    case MOSTRAR_INVENTARIO:
        //FALTA MOSTRARLO LINDO CREO QUE HAY QUE ASUMIR QUE VIENE TODO BIEN
        //LOS MATERIALES SON UNA CLASE QUE DICE LA CANTIDAD!!!! ESTO NO ESTA MUY BIEN, CORREGIR SOLO 
        //SI HAY TIEMPO
        andypolis.mostrar_inventario();
        volver();
        break;

    case RECOLECTAR_RECURSOS:
        //FALTA TODO
        break;

    case LLUVIA_RECURSOS:
        //FALTA TODO
        break;

    case SALIR:
        // FALTA GUARDAR EL ARCHIVO UBICACIONES Y MATERIALES
        //y "LIMPIAR" el mapa si quedaron edificios construidos
        break;
    //FALTA emprolijar tooooooodo el codigo
    default:
        msjeError("Error: opcion invalida");
    }
}

bool es_opcion_valida(int elegida)
{
    return (elegida >= OPCION_MINIMA && elegida <= OPCION_MAXIMA);
}
