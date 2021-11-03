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

void mostrar_menuInicial(Mapa &andypolis, Lista<Edificio*> & edificios, Parser parser)
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
        procesar_opcion(opcion_elegida, andypolis, edificios, parser);
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

void procesar_opcion(int opcion_elegida, Mapa &andypolis, Lista<Edificio*> & edificios, Parser & parser)
{

    //ESTA PARTE DEBERIA ESTAR EN OTRO LADO 
    
    //Lista<Material*> materiales;
   
    //parser.cargar(materiales,"materiales.txt");
  int i = 1;
  string nombre = "Yacimiento";
   
    switch (opcion_elegida)
    {
  
    case CONSTRUIR_EDIFICIO:
        // construir_edificio(mapa,edificios_array, materiales_array, ubicaciones_array);
        /*se pide la coordenada en el mapa y se modifica en la lista de edificios y materiales
        hay que modificar el archivo de ubicaciones_array */
       
        while(edificios[i]->obtener_nombre() == nombre){i++;}

        if(nombre == "Yacimiento")
            andypolis.agregar_edificio(0,2, new Yacimiento(edificios[--i]));
        if(nombre == "Aserradero")
            andypolis.agregar_edificio(0,3, new Aserradero(edificios[--i]));
        if(nombre == "Escuela")
            andypolis.agregar_edificio(0,3, new Escuela(edificios[--i]));
        if(nombre == "Fabrica")
            andypolis.agregar_edificio(0,3, new Fabrica(edificios[--i]));
        if(nombre == "Mina")
            andypolis.agregar_edificio(0,3, new Mina(edificios[--i]));
        if(nombre == "Obelisco")
            andypolis.agregar_edificio(0,3, new Obelisco(edificios[--i]));
        if(nombre == "Planta Electrica")
            andypolis.agregar_edificio(0,3, new PlantaElectrica(edificios[--i]));
        
        i = 1;
        break;

    case LISTAR_CONSTRUIDOS:
          
        // listar_construidos(edificios_array)
        /*edificio va a tener un atributo que sea cant_construido*/
        break;

    case LISTAR_TODOS:
        // listar_todos_edificios(edificios_array);
        for(int i = 1; i < edificios.mostrar_cantidad()+1; i++ ){
           cout << edificios[i]->obtener_nombre() << '\t'
                << edificios[i]->obtener_madera() << '\t'
                << edificios[i]->obtener_metal()  << '\t'
                << edificios[i]->obtener_piedra() << '\t'
                << edificios[i]->obtener_cant_max() << '\t'
                << edificios[i]->obtener_cant_max() << '\t' //ESTO HABRIA QUE RESTARLO CON CUANTOS HAY YA
                << edificios[i]->obtener_cant_mat_producido() << ' '
                << edificios[i]->obtener_mat_producido()    
                << endl;
        }
        volver();
        break;

    case DEMOLER_POR_COORDENADA:
        // demoler_edificio(mapa,edificios_array, materiales_array, ubicaciones_array);
        /*idem construir*/
        break;

    case MOSTRAR_MAPA:
        andypolis.mostrar_mapa();
        volver();
        break;

    case CONSULTAR_COORDENADA:
        andypolis.consultar_coordenada(0, 3);
        volver();
        break;

    case MOSTRAR_INVENTARIO:
        // mostrar_inventario(materiales_array);
        break;

    case RECOLECTAR_RECURSOS:
        // recolectar_recursos(edificios_array);
        /*edificio va a tener un atributo que sea cant_construido y cant_mat_producido*/
        break;

    case LLUVIA_RECURSOS:
        // lluvia_recursos(casillero **mapa, material *materiales_array);
        /*se genera una coordenada random y se ubica el material en el casillero
        la lista de materiales es para actualizarla (opcional pero da puntos)*/
        break;

    case SALIR:
        // guardar_archivos(mapa, edificios_array, materiales_array, ubicaciones_array);
        parser.borrar(edificios);
        break;

    default:
        msjeError("Error: opcion invalida");
    }
}

bool es_opcion_valida(int elegida)
{
    return (elegida >= OPCION_MINIMA && elegida <= OPCION_MAXIMA);
}
