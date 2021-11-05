
#include "ciudad.hpp"

#include "ciudad.hpp"

// CONSTRUCTOR-DESTRUCTOR--------------------------
// FALTA REVISAR PARSER
void Ciudad::procesar_archivos()
{
    mapa.cargar("mapa.txt");
    mapa.cargar_ubicaciones("ubicaciones.txt");
    parser.cargar(edificios, "edificios.txt");
    parser.cargar(materiales, "materiales.txt");
    cargar_ubicaciones();
}

void Ciudad::mostrar_mapa()
{
    mapa.mostrar_mapa();
}

void Ciudad::listar_edificios()
{
    for (int i = 1; i < edificios.mostrar_cantidad() + 1; i++)
    {
        cout << edificios[i]->obtener_nombre() << '\t'
             << edificios[i]->obtener_madera() << '\t'
             << edificios[i]->obtener_metal() << '\t'
             << edificios[i]->obtener_piedra() << '\t'
             << edificios[i]->obtener_cant_max() << '\t'
             << edificios[i]->obtener_cant_max() << '\t' // ESTO HABRIA QUE RESTARLO CON CUANTOS HAY YA
             << edificios[i]->obtener_cant_mat_producido() << ' '
             << edificios[i]->obtener_mat_producido()
             << endl;
    }
}

void Ciudad::mostrar_inventario()
{
    for (int i = 1; i < materiales.mostrar_cantidad() + 1; i++)
    {
        cout << materiales[i]->obtener_nombre() << '\t'
             << materiales[i]->obtener_cantidad() << ' '
             << endl;

        // materiales[i]->mostrar_material();
    }
}

Ciudad::~Ciudad()
{
    parser.borrar(edificios);
    parser.borrar(materiales);
}

void Ciudad::consultar_coordenada(int x, int y)
{
    mapa.consultar_coordenada(x, y);
}

// CONSTRUCTOR-DESTRUCTOR--------------------------
Ciudad::Ciudad()
{
    parser.cargar(edificios, PATH_EDIFICIOS);
    parser.cargar(materiales, PATH_MATERIALES);
    mapa = Mapa(PATH_MAPA);
    mapa.cargar_ubicaciones(PATH_UBICACIONES);

    cant_materiales = materiales.mostrar_cantidad();
    cant_edificios = edificios.mostrar_cantidad();
    cant_ubicaciones = ubicaciones.mostrar_cantidad();
}

// FUNCIONES DEL MENU PRINCIPAL--------------------
// FALTA
void Ciudad::construir_edificio(string nombre, int x, int y)
{

    // primero reviso que el nombre sea un tipo de edificio posible
    // voy al casillero (x,y) y verifico que sea construible y que no ningun otro edificio
    // si es construible y no hay otro edificio:
    // this->mapa.construir_edificio(nombre, x, y);

    // resto la cantidad de materiales necesarios
    this->restar_materiales_construccion(nombre);

    cout << "falta hacer jeje" << endl;
}

// FALTA
void Ciudad::listar_edificios_construidos()
{
    // acordarse de impirmir el caso de que  no tenga edificios construidos

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

// ya esta
void Ciudad::listar_edificios()
{
    for (int i = 0; i < this->cant_edificios; i++)
    {
        this->edificios[i]->mostrar_edificio();
    }
}
// FALTA
void Ciudad::demoler_edificio(int x, int y)
{
    // this->Mapa.destruir_edificio(x,y);
    // this.recolectar_materiales_construccion()
    cout << "falta hacer jeje" << endl;
}

// FALTA
void Ciudad::recolectar_recursos()
{
    // recorro el mapa y donde hay un casillero construible:
    // me fijo si hay un edificio
    // me fijo si ese tipo de edificio da recursos
    // lo voy guardandolo en valores aux: cant_madera, cant_piedra, cant_metal
    // recorro la lista de materiales y guardo los recursos segun que tipo sea y cantidad

    cout << "falta hacer jeje" << endl;
}

// FALTA
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

// FALTA
void Ciudad::guardar_archivos()
{
    cout << "falta hacer jeje" << endl;
}

// FUNCIONES AUXILIARES----------------------------
void Ciudad::agregar_material_en_coordenada(string nombre_material, int cantidad, int x, int y)
{
    cout << "falta hacer jeje" << endl;
}

void Ciudad::construir(int x, int y, string edificio)
{
    chequear_stock(buscar_edificio(edificio));
    // chequear_casillero()

    if (edificio == "yacimiento")
        mapa.agregar_edificio(x, y, new Yacimiento(edificios[buscar_edificio(edificio)]));
    if (edificio == "aserradero")
        mapa.agregar_edificio(x, y, new Aserradero(edificios[buscar_edificio(edificio)]));
    if (edificio == "escuela")
        mapa.agregar_edificio(x, y, new Escuela(edificios[buscar_edificio(edificio)]));
    if (edificio == "fabrica")
        mapa.agregar_edificio(x, y, new Fabrica(edificios[buscar_edificio(edificio)]));
    if (edificio == "mina")
        mapa.agregar_edificio(x, y, new Mina(edificios[buscar_edificio(edificio)]));
    if (edificio == "obelisco")
        mapa.agregar_edificio(x, y, new Obelisco(edificios[buscar_edificio(edificio)]));
    if (edificio == "planta electrica")
        mapa.agregar_edificio(x, y, new PlantaElectrica(edificios[buscar_edificio(edificio)]));
}

void Ciudad::restar_materiales_construccion(string nombre_edificio)
{
    // recorro lista de edificios
    for (int i = 0; i < this->cant_edificios; i++)
    {
        if (this->edificios[i]->obtener_nombre() == nombre_edificio)
        {
            // recorro la lista de materiales y modifico la cantidad
            for (int j = 0; j < this->cant_edificios; j++)
            {
                if (this->materiales[j]->obtener_nombre() == "madera")
                    this->materiales[j]->modificar_cantidad(-this->edificios[i]->obtener_madera());

                if (this->materiales[j]->obtener_nombre() == "piedra")
                    this->materiales[j]->modificar_cantidad(-this->edificios[i]->obtener_piedra());

                if (this->materiales[j]->obtener_nombre() == "metal")
                    this->materiales[j]->modificar_cantidad(-this->edificios[i]->obtener_metal());
            }
        }
    }
}

void Ciudad::agregar_ubicacion(string nombre_edificio, int x, int y)
{
    cout << "hola";
}

void Ciudad::demoler_edificio(int x, int y)
{
    mapa.demoler_edificio(x, y);
}

void Ciudad::recolectar_materiales_reciclados(string nombre_edificio)
{
    for (int i = 0; i < this->cant_edificios; i++)
    {
        if (this->edificios[i]->obtener_nombre() == nombre_edificio)
        {
            // recorro la lista de materiales y modifico la cantidad
            for (int j = 0; j < this->cant_edificios; j++)
            {
                if (this->materiales[j]->obtener_nombre() == "madera")
                    this->materiales[j]->modificar_cantidad(this->edificios[i]->obtener_madera() / 2);

                if (this->materiales[j]->obtener_nombre() == "piedra")
                    this->materiales[j]->modificar_cantidad(this->edificios[i]->obtener_piedra() / 2);

                if (this->materiales[j]->obtener_nombre() == "metal")
                    this->materiales[j]->modificar_cantidad(this->edificios[i]->obtener_metal() / 2);
            }
        }
    }
}

void Ciudad::eliminar_ubicacion(string nombre_edificio, int x, int y)
{
    cout << "hola";
}

int Ciudad::buscar_edificio(string edificio)
{
    int i = 1;

    int cantidad = edificios.mostrar_cantidad();
    while (cantidad && (edificios[i]->obtener_nombre() != edificio))
    {
        i++;
        --cantidad;
    }

    return i;
}

void Ciudad::chequear_stock(int i)
{
    int cuenta = 0;
    for (int j = 1; j < materiales.mostrar_cantidad() + 1; j++)
    {
        if (materiales[j]->obtener_nombre() == "Piedra")
        {
            cuenta = materiales[j]->obtener_cantidad() - edificios[i]->obtener_piedra();
            if (cuenta < 0)
            {
                cout << "falta " << materiales[j]->obtener_nombre() << endl;
                // flag = 0;
            }
            else
                materiales[j]->modificar_cantidad(cuenta);
        }
        if (materiales[j]->obtener_nombre() == "Madera")
        {
            cuenta = materiales[j]->obtener_cantidad() - edificios[i]->obtener_madera();
            if (cuenta < 0)
            {
                cout << "falta " << materiales[j]->obtener_nombre() << endl;
                // flag = 0;
            }
            else
                materiales[j]->modificar_cantidad(cuenta);
        }
        if (materiales[j]->obtener_nombre() == "Metal")
        {
            cuenta = materiales[j]->obtener_cantidad() - edificios[i]->obtener_metal();
            if (cuenta < 0)
            {
                cout << "falta " << materiales[j]->obtener_nombre() << endl;
                // flag = 0;
            }
            else
                materiales[j]->modificar_cantidad(cuenta);
        }
    }
}

void Ciudad::cargar_ubicaciones()
{
    Ubicacion edificio;
    for (int i = 1; i < mapa.cant_edificios() + 1; i++)
    {
        edificio = mapa.devolver_ubicacion(i);
        construir(edificio.coord_x, edificio.coord_y, edificio.nombre);
    }
}

void Ciudad::mostrar_ubicaciones()
{
    mapa.mostrar_ubicaciones();
}
