#include "ciudad.hpp"
#include <string>
#include <iomanip>

Ciudad::Ciudad(const string &PATH1, const string &PATH2, const string &PATH3, Terreno &terreno, Constructor &bob, Recurso &recurso)
{
    cargar_provisiones(PATH2, recurso);
    inventario.cargar(PATH2, recurso);
    cargar_ubicaciones(PATH3);

    fstream archivo_mapa(PATH1, ios::in);

    if (!archivo_mapa.is_open())
    {
        cout << "No se encontro un archivo con nombre \"" << PATH1 << "\", se va a crear el archivo" << endl;
        archivo_mapa.open(PATH1, ios::out);
        archivo_mapa.close();
        archivo_mapa.open(PATH1, ios::in);
    }

    string casillero, filas_, columnas_;

    archivo_mapa >> filas_;
    archivo_mapa >> columnas_;
    filas = stoi(filas_);
    columnas = stoi(columnas_);

    mapa = new Casillero **[filas];

    for (int i = 0; i < filas; i++)
    {
        mapa[i] = new Casillero *[columnas];
        for (int j = 0; j < columnas; j++)
        {
            archivo_mapa >> casillero;
            mapa[i][j] = terreno.agregar(casillero);
        }
    }

    cargar_ubicaciones(bob);
    llenarcoordenadatransitable();
}

Ciudad::~Ciudad()
{
    demoler_todo();

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            delete mapa[i][j];

    for (int i = 0; i < filas; i++)
        delete[] mapa[i];

    delete[] mapa;
}

void Ciudad::guardar_archivos()
{
    guardar_ubicaciones();
    guardar_materiales();
    msjeOK("Se guardaron los cambios en los archivos ubicaciones.txt y materiales.txt");
    msjeInstruccion("Hasta pronto!!");
}

void Ciudad::mostrar_mapa()
{
    msjeInstruccion("MAPA DE ANDYPOLIS:");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            mapa[i][j]->display();
        }
        cout << endl;
    }
}

void Ciudad::consultar_coordenada_cin()
{
    string x, y;
    msjeInstruccion("Ingrese las coordenadas del mapa para demoler:");
    msjeInstruccion("Coordenada X:");
    cin >> x;
    msjeInstruccion("Coordenada Y:");
    cin >> y;
    consultar_coordenada(stoi(x), stoi(y));
}
void Ciudad::consultar_coordenada(int i, int j)
{
    cout << "Hola, estás en la posición (" << i << ", " << j << ")" << endl;
    mapa[i][j]->mostrar();
}

void Ciudad::demoler_por_coordenada()
{
    string x, y;
    msjeInstruccion("Ingrese las coordenadas del mapa para demoler:");
    msjeInstruccion("Coordenada X:");
    cin >> x;
    msjeInstruccion("Coordenada Y:");
    cin >> y;
    demoler_edificio(stoi(x), stoi(y));
}

void Ciudad::construir_por_nombre_coordenada(Constructor &bob)
{
    string x, y, nombre_edificio, aux;
    msjeInstruccion("Ingrese el nombre del edificio que quiere construir:");
    cin >> nombre_edificio;
    if (nombre_edificio == "planta")
    {
        cin >> aux;
        nombre_edificio = nombre_edificio + " " + aux;
    }

    if (chequear_permisos_edificio(nombre_edificio, bob))
    {
        msjeInstruccion("Ingrese las coordenadas donde quiere construirlo.");
        msjeInstruccion("Coordenada X:");
        cin >> x;
        msjeInstruccion("Coordenada Y:");
        cin >> y;
        construir(stoi(x), stoi(y), nombre_edificio, bob);
    }
    else
        msjeError("No existe ese edificio para construir");
}
void Ciudad::construir(int x, int y, const string &eledificio, Constructor &bob)
{
    if (x < filas && y < columnas)
    {
        Edificio *edificio = bob.construye(eledificio);
        if (inventario.chequear_stock(edificio, true))
        {
            if (mapa[x][y]->agregar(edificio))
            {
                agregar_ubicacion(x, y, eledificio);
                msjeOK("Se construyo el edificio y se agrego a la lista de ubicaciones");
            }
            else
                delete edificio;
        }
        else
            msjeError("No hay materiales suficientes para la construccion de ese edificio :(");
    }
    if (x > filas)
        msjeError("Esa coordenada X no existe en el mapa");
    if (y > columnas)
        msjeError("Esa coordenada Y no existe en el mapa");
}

void Ciudad::cargar_ubicaciones(Constructor &bob)
{
    Ubicacion ubicacion;
    for (int i = 1; i < ubicaciones.mostrar_cantidad() + 1; i++)
    {
        ubicacion = ubicaciones[i];
        Edificio *edificio = bob.construye(ubicacion.nombre);
        mapa[ubicacion.coord_x][ubicacion.coord_y]->agregar(edificio);
    }
}

void Ciudad::cargar_ubicaciones(const string &PATH)
{
    fstream archivo_ubicaciones(PATH, ios::in);

    if (!archivo_ubicaciones.is_open())
    {
        msjeError("No se encontro un archivo con nombre \"" + PATH + "\", se va a crear el archivo");
        archivo_ubicaciones.open(PATH, ios::out);
        archivo_ubicaciones.close();
        archivo_ubicaciones.open(PATH, ios::in);
    }

    Ubicacion ubicacion;

    string nombre, aux, coord_x, coord_y;
    while (getline(archivo_ubicaciones, nombre, ' '))
    {
        if (nombre != "planta")
        {
            ubicacion.nombre = nombre;
            getline(archivo_ubicaciones, aux, '(');

            getline(archivo_ubicaciones, coord_x, ',');
            ubicacion.coord_x = stoi(coord_x);

            getline(archivo_ubicaciones, aux, ' ');
            getline(archivo_ubicaciones, coord_y, ')');
            ubicacion.coord_y = stoi(coord_y);
            getline(archivo_ubicaciones, aux);

            ubicaciones.alta(ubicacion);
        }
        else
        {
            getline(archivo_ubicaciones, aux, ' ');
            ubicacion.nombre = nombre + " " + aux;

            getline(archivo_ubicaciones, aux, ' ');

            getline(archivo_ubicaciones, coord_x, ',');
            ubicacion.coord_x = stoi(coord_x);

            getline(archivo_ubicaciones, aux, ' ');
            getline(archivo_ubicaciones, coord_y, ')');
            ubicacion.coord_y = stoi(coord_y);
            getline(archivo_ubicaciones, aux);
            ubicaciones.alta(ubicacion);
        }
    }
}

void Ciudad::cargar_provisiones(const string &PATH, Recurso &recurso)
{
    fstream archivo_materiales(PATH, ios::in);

    if (!archivo_materiales.is_open())
    {
        msjeError("No se encontro un archivo con nombre \"" + PATH + "\", se va a crear el archivo");
        archivo_materiales.open(PATH, ios::out);
        archivo_materiales.close();
        archivo_materiales.open(PATH, ios::in);
    }

    string nombre, cantidad;
    while (archivo_materiales >> nombre)
    {
        archivo_materiales >> cantidad;
        materiales1.alta(recurso.dar_material(nombre, stoi(cantidad)));
    }
}

void Ciudad::mostrar_inventario()
{
    inventario.mostrar_inventario();
}

bool Ciudad::chequear_permisos_edificio(const string &eledificio, Constructor &bob)
{
    Edificio *edificio = bob.construye(eledificio);
    int flag = 1;
    if (edificio)
    {
        if (inventario.chequear_stock(edificio, false))
        {
            msjeOK("Hay materiales suficientes para construir este edificio");
            flag = 1;
            if (edificio->obtener_cant_max() > construidos(eledificio))
            {
                msjeOK("y todavia hay capacidad para construir edificios de ese estilo!");
                flag = 1;
            }
            else
            {
                flag = 0;
                msjeError("pero ya no se pueden construir mas edificios de ese estilo. Llegamos al maximo :(");
            }
        }
        else
            flag = 0;
        delete edificio;
    }
    else
    {
        flag = 0;
    }
    return flag;
}

void Ciudad::agregar_ubicacion(int x, int y, string edificio)
{
    Ubicacion ubicacion;
    ubicacion.nombre = edificio;
    ubicacion.coord_x = x;
    ubicacion.coord_y = y;
    ubicaciones.alta(ubicacion);
}

void Ciudad::demoler_edificio(int x, int y)
{
    // int cuenta = 0;
    if (x < filas && y < columnas)
    {
        Edificio *edificio = mapa[x][y]->mostrar_edificio();

        if (edificio)
        {
            msjeInstruccion("Se va a eliminar un edificio del tipo '" + edificio->obtener_nombre() + "'");
            inventario.llenar_stock(edificio);
        }
        mapa[x][y]->demoler();
        quitar_ubicacion(x, y);
        msjeOK("Se demolio el edificio y se elimino de la lista de ubicaciones");
    }
    if (x > filas)
        msjeError("Esa coordenada X no existe en el mapa");
    if (y > columnas)
        msjeError("Esa coordenada Y no existe en el mapa");
}

bool Ciudad::guardar_ubicaciones()
{
    ofstream ubicaciones_out;
    ubicaciones_out.open("ubicaciones.txt");

    if (ubicaciones_out.is_open())
    {
        for (int i = 1; i < ubicaciones.mostrar_cantidad() + 1; i++)
        {
            ubicaciones_out << ubicaciones[i].nombre << " "
                            << "(" << ubicaciones[i].coord_x << ", "
                            << ubicaciones[i].coord_y << ")" << endl;
        }
        return true;
    }
    else
        return false;
}

void Ciudad::guardar_materiales()
{
    ofstream archivo_materiales("materiales.txt");
    for (int i = 1; i < materiales1.mostrar_cantidad() + 1; i++)
    {
        archivo_materiales << materiales1[i]->obtener_nombre() << ' ' << materiales1[i]->obtener_cantidad() << '\n';
        delete materiales1[i];
    }
}

void Ciudad::demoler_todo()
{
    for (int i = 1; i < ubicaciones.mostrar_cantidad() + 1; i++)
        mapa[ubicaciones[i].coord_x][ubicaciones[i].coord_y]->demoler();
    for (int i = 1; i < materiales.mostrar_cantidad() + 1; i++)
        mapa[materiales[i].coord_x][materiales[i].coord_y]->demoler();
}

void Ciudad::mostrar_ubicaciones()
{
    Lista<Ubicacion> copia;
    Lista<Ubicacion> auxiliar;
    int cant = 1;

    cout << left << TXT_BOLD << TXT_UNDERLINE << BGND_BLUE_4
         << setw(23) << "Cantidad" << '\t'
         << setw(23) << "Tipo de edificio" << '\t'
         << setw(23) << "Coord X" << '\t'
         << setw(23) << "Coord Y"
         << END_COLOR << endl;
    for (int i = 1; i < ubicaciones.mostrar_cantidad() + 1; i++)
        copia.alta(ubicaciones[i]);

    for (int i = 1; i < copia.mostrar_cantidad() + 1; i++)
    {
        auxiliar.alta(copia[i]);
        for (int j = i + 1; j < copia.mostrar_cantidad() + 1; j++)
        {
            if (auxiliar[1].nombre == copia[j].nombre)
            {
                auxiliar.alta(copia[j]);
                cant++;
                copia.baja(j);
                --j;
            }
        }
        cout << left
             << setw(23) << cant << '\t'
             << setw(23) << auxiliar[1].nombre << '\t';
        for (int i = 1; i < auxiliar.mostrar_cantidad() + 1; i++)
        {
            cout << left
                 << setw(23) << auxiliar[i].coord_x << '\t'
                 << setw(23) << auxiliar[i].coord_y << '\t';
        }
        cout << endl;
        cant = 1;
        while (!auxiliar.vacia())
            auxiliar.baja(1);
    }
}

int Ciudad::construidos(const string &edificio)
{

    int cant = 0;
    for (int i = 1; i < ubicaciones.mostrar_cantidad() + 1; i++)
        if (ubicaciones[i].nombre == edificio)
            cant++;

    return cant;
}

void Ciudad::recolectar()
{
    Edificio *edificio;
    int cuenta;

    msjeOK("Se recolectaron los siguientes materiales:");
    for (int i = 1; i < ubicaciones.mostrar_cantidad() + 1; i++)
    {
        edificio = mapa[ubicaciones[i].coord_x][ubicaciones[i].coord_y]->mostrar_edificio();
        for (int j = 1; j < materiales1.mostrar_cantidad() + 1; j++)
        {
            if (edificio->obtener_mat_producido() == materiales1[j]->obtener_nombre())
            {
                cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_cant_mat_producido();
                cout << "\t-> " << edificio->obtener_cant_mat_producido() << " unidades de " << materiales1[j]->obtener_nombre() << " del edificio del tipo '" << edificio->obtener_nombre() << "'" << endl;
                materiales1[j]->modificar_cantidad(cuenta);
            }
        }
    }
    msjeOK("Se guardaron los materiales en la lista de materiales. Pueden ser usados para construir nuevos edificios :)");
}

void Ciudad::quitar_ubicacion(int x, int y)
{
    for (int i = 1; i < ubicaciones.mostrar_cantidad() + 1; i++)
        if (ubicaciones[i].coord_x == x && ubicaciones[i].coord_y == y)
            ubicaciones.baja(i);
}

void Ciudad::llenarcoordenadatransitable()
{
    Ubicacion coordenada;

    for (int x = 0; x < filas; x++)
        for (int y = 0; y < columnas; y++)
            if (mapa[x][y]->estransitable())
            {
                coordenada.coord_x = x;
                coordenada.coord_y = y;
                coordenadasTransitables.alta(coordenada);
            }
}

void Ciudad::lluvia(Recurso &recurso)
{
    int numero;

    if (coordenadasTransitables.mostrar_cantidad() > 6)
    {
        cout << "LLUVIA DE RECURSOS!" << endl;
        int cant_metal = rand() % (1 + 4 - 2) + 2;
        cout << "Cantidad de metales generados: " << cant_metal << endl;

        while (cant_metal)
        {
            numero = rand() % (1 + coordenadasTransitables.mostrar_cantidad() - 1) + 1;
            mapa[coordenadasTransitables[numero].coord_x][coordenadasTransitables[numero].coord_y]->agregar(recurso.dar_material("metal"));
            cout << "\t-> (" << coordenadasTransitables[numero].coord_x << ", " << coordenadasTransitables[numero].coord_y << ")" << endl;
            materiales.alta(coordenadasTransitables[numero]);
            coordenadasTransitables.baja(numero);
            cant_metal--;
        }

        int cant_piedra = rand() % (1 + 2 - 1) + 1;
        cout << "Cantidad de piedras generadas: " << cant_piedra << endl;

        while (cant_piedra)
        {
            numero = rand() % (1 + coordenadasTransitables.mostrar_cantidad() - 1) + 1;
            mapa[coordenadasTransitables[numero].coord_x][coordenadasTransitables[numero].coord_y]->agregar(recurso.dar_material("piedra"));
            cout << "\t-> (" << coordenadasTransitables[numero].coord_x << ", " << coordenadasTransitables[numero].coord_y << ")" << endl;
            materiales.alta(coordenadasTransitables[numero]);
            coordenadasTransitables.baja(numero);
            cant_piedra--;
        }

        int cant_madera = rand() % (2);
        cout << "Cantidad de maderas generadas: " << cant_madera << endl;

        while (cant_madera)
        {
            numero = rand() % (1 + coordenadasTransitables.mostrar_cantidad() - 1) + 1;
            mapa[coordenadasTransitables[numero].coord_x][coordenadasTransitables[numero].coord_y]->agregar(recurso.dar_material("madera"));
            cout << "\t-> (" << coordenadasTransitables[numero].coord_x << ", " << coordenadasTransitables[numero].coord_y << ")" << endl;
            materiales.alta(coordenadasTransitables[numero]);
            coordenadasTransitables.baja(numero);
            cant_madera--;
        }
    }
}

void listar_edificios(Ciudad &andypolis, Constructor &bob)
{

    int cant_edificios = bob.cant_edificios();
    Edificio *edificio;

    cout << left << TXT_BOLD << TXT_UNDERLINE << BGND_BLUE_4
         << setw(23) << "Nombre" << '\t'
         << setw(23) << "Cant de madera" << '\t'
         << setw(23) << "Cant de metal" << '\t'
         << setw(23) << "Cant de piedra" << '\t'
         << setw(23) << "Cant maxima" << '\t'
         << setw(23) << "Se pueden construir.." << '\t'
         << setw(23) << "Cant de produccion" << '\t'
         << setw(23) << "Tipo de material que produce"
         << END_COLOR << endl;
    for (int i = 1; i < cant_edificios + 1; i++)
    {
        edificio = bob.mostrar_edificio(i);
        cout << left
             << setw(23) << edificio->obtener_nombre() << '\t'
             << setw(23) << edificio->obtener_madera() << '\t'
             << setw(23) << edificio->obtener_metal() << '\t'
             << setw(23) << edificio->obtener_piedra() << '\t'
             << setw(23) << edificio->obtener_cant_max() << '\t'
             << setw(23) << edificio->obtener_cant_max() - andypolis.construidos(edificio->obtener_nombre()) << '\t'
             << setw(23) << edificio->obtener_cant_mat_producido() << '\t'
             << setw(23) << edificio->obtener_mat_producido()
             << endl;
    }
}