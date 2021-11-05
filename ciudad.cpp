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

void Ciudad::demoler_edificio(int x, int y)
{
    mapa.demoler_edificio(x, y);
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

void Ciudad::mostrar_inventario()
{
    for (int i = 1; i < materiales.mostrar_cantidad() + 1; i++)
    {
        cout << materiales[i]->obtener_nombre() << '\t'
             << materiales[i]->obtener_cantidad() << ' '
             << endl;
    }
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

void Ciudad::mostrar_ubicaciones()
{
    mapa.mostrar_ubicaciones();
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
Ciudad::~Ciudad()
{
    parser.borrar(edificios);
    parser.borrar(materiales);
}

void Ciudad::consultar_coordenada(int x, int y)
{
    mapa.consultar_coordenada(x, y);
}

void Ciudad::recolectar_recursos()
{
    // recorro la lista de ubicaciones
    // busco la ubicacion en mapa
    // guardo en materiales
}

void Ciudad::lluvia_recursos()
{
    srand((unsigned)time(NULL));
    // int i = 0, cant_permitida = 1, x = 0, y = 0;

    /*REVISAR MADERA Y PIEDRA PROQUE DIVIDE POR CERO Y NO DAHH AUNQUE LO PROBE SIN ESE COMPILADOR Y FUNCIONA
    VER OTRA FORMA!!!*/
    int cant_madera = rand() % (CANT_MAX_RANDOM_MADERA - CANT_MIN_RANDOM_MADERA) + CANT_MIN_RANDOM_MADERA;
    int cant_piedra = rand() % (CANT_MAX_RANDOM_PIEDRA - CANT_MIN_RANDOM_PIEDRA) + CANT_MIN_RANDOM_PIEDRA;
    int cant_metal = rand() % (CANT_MAX_RANDOM_METAL - CANT_MIN_RANDOM_METAL) + CANT_MIN_RANDOM_METAL;

    cout << cant_madera << endl;
    cout << cant_piedra << endl;
    cout << cant_metal << endl;
}

void Ciudad::guardar_archivos()
{
    if (!guardar_materiales())
        cout << "No se pudieron guardar los materiales" << endl;
    else if (!guardar_ubicaciones())
        cout << "No se pudieron guardar las ubicaciones" << endl;
    else
        cout << "Se guardaron los cambios en ubicaciones.txt y materiales.txt! Hasta pronto :)" << endl;
}

bool Ciudad::guardar_ubicaciones()
{
    ofstream ubicaciones_out;
    ubicaciones_out.open("ubicaciones.txt");

    if (ubicaciones_out.is_open())
    {
        for (int i = 1; i < mapa.cant_edificios() + 1; i++)
        {
            ubicaciones_out << mapa.ubicacion_nombre(i) << " "
                            << "(" << mapa.ubicacion_coord_x(i) << ", "
                            << mapa.ubicacion_coord_y(i) << ")" << endl;
        }
        return true;
    }
    else
        return false;
}

bool Ciudad::guardar_materiales()
{
    ofstream materiales_out;
    materiales_out.open("materiales.txt");

    if (materiales_out.is_open())
    {
        for (int i = 1; i < materiales.mostrar_cantidad() + 1; i++)
        {
            materiales_out << materiales[i]->obtener_nombre() << " "
                           << materiales[i]->obtener_cantidad() << endl;
        }
        return true;
    }
    else
        return false;
}
