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
