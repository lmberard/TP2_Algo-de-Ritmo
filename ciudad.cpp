
#include "ciudad.hpp"

// CONSTRUCTOR-DESTRUCTOR--------------------------
void Ciudad::procesar_archivos()
{
    cout << "falta hacer jeje" << endl;
}

Ciudad::Ciudad()
{
    cout << "falta hacer jeje" << endl;
}

Ciudad::~Ciudad()
{
    cout << "falta hacer jeje" << endl;
}

// FUNCIONES DEL MENU PRINCIPAL--------------------
void Ciudad::construir_edificio(string nombre, int x, int y)
{
    // segun el nombre creo un objecto EdificioNombre
    // agrego un nuevo espacio en lal ista de materiales y lo guardo

    cout << "falta hacer jeje" << endl;
}

void Ciudad::listar_edificios_construidos()
{

    /*
    lo que se me ocurre es primero mostrar la lista de ubicaciones
    que vaya guardando las ubicaciones de cada tipo de edificio
    asi muestra todo de una? puede estar repetido el nombre?
    sino voy guardando en valores auxiliares la info.
    total ya se que voy a tener solo esos tipos de edificios pero mmm rancio
    */

    /*
    otra forma es recorrer el mapa pero es peor que lo anterior creo
    */
    cout << "falta hacer jeje" << endl;
}

void Ciudad::demoler_edificio(int x, int y)
{
    // this->Mapa.destruir_edificio(x,y);
    // this.recolectar_materiales_construccion()
    cout << "falta hacer jeje" << endl;
}

void Ciudad::mostrar_mapa()
{
    // falta mostrar lo que hay en cada casillero!!
    // this->mapa.mostrar_mapa();
}

void Ciudad::consultar_coordenada(int x, int y)
{
    // this->mapa.consultar_coordenada(x, y);
}

void Ciudad::mostrar_inventario()
{
    /*
    for(int i = 0; i < this->cant_materiales; i++)
    {
        this->materiales[i].mostrar();
    }*/
    cout << "falta hacer jeje" << endl;
}

void Ciudad::recolectar_recursos()
{
    // recorro el mapa y donde hay un casillero construible:
    // me fijo si hay un edificio
    // me fijo si ese tipo de edificio da recursos
    // lo voy guardandolo en valores aux: cant_madera, cant_piedra, cant_metal
    // recorro la lista de materiales y guardo los recursos segun que tipo sea y cantidad

    cout << "falta hacer jeje" << endl;
}

void Ciudad::lluvia_recursos()
{
    srand((unsigned)time(NULL));
    // int i = 0, cant_permitida = 1, x = 0, y = 0;

    /*REVISAR MADERA Y PIEDRA PROQUE DIVIDE POR CERO Y NO DAHH AUNQUE LO PROBE SIN ESE COMPILADOR Y FUNCIONA
    VER OTRA FORMA!!!*/
    // int cant_madera = rand() % (1 + CANT_MAX_RANDOM_MADERA - CANT_MIN_RANDOM_MADERA) + CANT_MIN_RANDOM_MADERA;
    // int cant_piedra = rand() % (1 + CANT_MAX_RANDOM_PIEDRA - CANT_MIN_RANDOM_PIEDRA) + CANT_MIN_RANDOM_PIEDRA;
    int cant_metal = rand() % (1 + CANT_MAX_RANDOM_METAL - CANT_MIN_RANDOM_METAL) + CANT_MIN_RANDOM_METAL;

    // cout << "Cantidad de madera:" << cant_madera << endl;
    // cout << "Cantidad de piedra:" << cant_piedra << endl;
    cout << "Cantidad de metal:" << cant_metal << endl;
    /*
    for(i = 0; i <= cant_madera; i++)
    {
        //generar un valor aleatorio para x e y dentro de los casilleros transitables
        agregar_material_en_coordenada("madera", cant_permitida, x, y);
    }

    for(i = 0; i <= cant_piedra; i++)
    {
        //generar un valor aleatorio para x e y dentro de los casilleros transitables
        agregar_material_en_coordenada("piedra", cant_permitida, x, y);
    }

    for(i = 0; i <= cant_metal; i++)
    {
        //generar un valor aleatorio para x e y dentro de los casilleros transitables
        agregar_material_en_coordenada("metal", cant_permitida, x, y);
    }
    */
    cout << "falta hacer jeje" << endl;
}

void Ciudad::guardar_archivos()
{
    cout << "falta hacer jeje" << endl;
}

// FUNCIONES AUXILIARES----------------------------

// LLUVIA DE RECURSOS
void Ciudad::agregar_material_en_coordenada(string nombre_material, int cantidad, int x, int y)
{
    cout << "falta hacer jeje" << endl;
}

// CONSTRUIR EDIFICIO
void Ciudad::agregar_edificio(string nombre_edificio, int x, int y)
{
    // edificios.agregar(nombre_edificio, x, y);
    cout << "falta hacer jeje" << endl;
}
void Ciudad::restar_materiales_construccion(string nombre_edificio)
{
    /*segun el nombre del edificio se elimina una cant diferente*/
    /*
    //recorro lista de edificios
     for(i = 0; i < this->cant_edificios; i++)
     {
         if(edificios[i].obtener_nombre() == nombre_edificio)
         {
             //recorro la lista de materiales
            for(j = 0; j < this->cant_edificios; j++)
            {
                if(materiales[j].obtener_nombre() == "madera")
                    materiales[j].modificar_cantidad(edificios[i].obtener_madera()/2);

                if(materiales[j].obtener_nombre() == "piedra")
                    materiales[j].modificar_cantidad(edificios[i].obtener_piedra()/2);

                if(materiales[j].obtener_nombre() == "metal")
                    materiales[j].modificar_cantidad(edificios[i].obtener_metal()/2);
            }
         }
     }
    */
    cout << "falta hacer jeje" << endl;
}

void Ciudad::agregar_ubicacion(string nombre_edificio, int x, int y)
{
    /*
    this->cant_ubicaciones ++;
    //creo memoria para uno espacio y lo agrego

    */
    cout << "falta hacer jeje" << endl;
}

// DESTRUIR EDIFICIO
void Ciudad::destruir_edificio(string nombre_edificio, int x, int y)
{
    cout << "falta hacer jeje" << endl;
}
void Ciudad::recolectar_materiales_reciclados(string nombre_edificio)
{
    cout << "falta hacer jeje" << endl;
}
void Ciudad::eliminar_ubicacion(string nombre_edificio, int x, int y)
{
    cout << "falta hacer jeje" << endl;
}
