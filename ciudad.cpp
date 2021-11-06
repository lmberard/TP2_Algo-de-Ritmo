#include "ciudad.hpp"

Ciudad::Ciudad(const string & PATH)
{
    bob.cargar("edificios.txt");
    cargar_provisiones("materiales.txt");
    cargar_ubicaciones("ubicaciones.txt");
    
    fstream archivo_mapa(PATH, ios::in);

    if (!archivo_mapa.is_open())
    {
        cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
        archivo_mapa.open(PATH, ios::out);
        archivo_mapa.close();
        archivo_mapa.open(PATH, ios::in);
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

    cargar_ubicaciones();
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

    bob.borrar();
    guardar_ubicaciones();
    for(int i = 1; i < provisiones.mostrar_cantidad()+1; i++)
        delete provisiones[i].material;
}


void Ciudad::mostrar_mapa()
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            mapa[i][j]->display();
        }
        cout << endl;
    }
}


void Ciudad::consultar_coordenada(int i, int j)
{
    cout << "Hola, estás en la posición" << i << j << endl;
    mapa[i][j]->mostrar();
}

void Ciudad::construir(int x, int y,const string & eledificio)
{
    Edificio * edificio = bob.construye(eledificio);
    mapa[x][y]->agregar(edificio);
    agregar_ubicacion(x,y,eledificio);
}

void Ciudad::cargar_ubicaciones()
{
    Ubicacion ubicacion; 
    for(int i = 1; i < ubicaciones.mostrar_cantidad() +1;i++){
        ubicacion = ubicaciones[i];
        Edificio * edificio = bob.construye(ubicacion.nombre);
        mapa[ubicacion.coord_x][ubicacion.coord_y]->agregar(edificio);
    }
}

void Ciudad::cargar_ubicaciones(const string& PATH)
{
    fstream archivo_ubicaciones(PATH, ios::in);

    if (!archivo_ubicaciones.is_open())
    {
        cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
        archivo_ubicaciones.open(PATH, ios::out);
        archivo_ubicaciones.close();
        archivo_ubicaciones.open(PATH, ios::in);
    }

    Ubicacion ubicacion;

    string nombre, aux, coord_x, coord_y;
    while (getline(archivo_ubicaciones, nombre, ' ')){
        if (nombre != "planta"){
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
        /*else{

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

        }*/
    }
}

void Ciudad::cargar_provisiones(const string & PATH)
{
    fstream archivo_materiales(PATH, ios::in);

    if (!archivo_materiales.is_open())
    {
        cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
        archivo_materiales.open(PATH, ios::out);
        archivo_materiales.close();
        archivo_materiales.open(PATH, ios::in);
    }

    Provision provision;
    string nombre, cantidad;
    while (archivo_materiales >> nombre)
    {

        archivo_materiales >> cantidad;
        provision.material = recurso.dar_material(nombre);
        provision.cantidad = stoi(cantidad);
        provisiones.alta(provision);
    }
}

void Ciudad::mostrar_inventario()
{
    for(int i = 1; i < provisiones.mostrar_cantidad()+1; i++ ){
           cout << provisiones[i].material->obtener_nombre() << '\t'
                << provisiones[i].cantidad << ' ' 
                << endl;
    }
}

bool Ciudad::chequear_permisos_edificio(const string & eledificio)
{
    Edificio * edificio = bob.construye(eledificio);
    int flag = 1;
    if(edificio){
        if(chequear_stock(edificio))
            flag = 1;
        else
            flag = 0;
        delete edificio;
    }
    else{
        flag = 0;
        cout << "todavia no esta ese" << endl;
    }
    return flag;
}

bool Ciudad::chequear_stock(Edificio * edificio)
{
    int cuenta = 0;
    bool flag = 1;
        
    for(int j = 1; j < provisiones.mostrar_cantidad()+1; j++ ){
        if(provisiones[j].material->obtener_nombre() == "piedra"){  
            cuenta = provisiones[j].cantidad - edificio->obtener_piedra();
            if(cuenta < 0 ){
                cout << "falta " << provisiones[j].material->obtener_nombre() << endl;
                flag = 0;
            }
            else
                provisiones[j].cantidad = cuenta;
        }
        if(provisiones[j].material->obtener_nombre() == "madera"){
            cuenta = provisiones[j].cantidad - edificio->obtener_madera();
            if(cuenta < 0 ){
                cout << "falta " << provisiones[j].material->obtener_nombre() << endl;
                flag = 0;
            }
            else
                provisiones[j].cantidad = cuenta;
        }
        if(provisiones[j].material->obtener_nombre() == "metal"){
            cuenta = provisiones[j].cantidad - edificio->obtener_metal();
            if(cuenta < 0 ){
                cout << "falta " << provisiones[j].material->obtener_nombre() << endl;
                flag = 0;
            }
            else
                provisiones[j].cantidad = cuenta;
        }
    }

    return flag;
}

void Ciudad::agregar_ubicacion(int x,int y,string edificio)
{
    Ubicacion ubicacion; 
    ubicacion.nombre = edificio;
    ubicacion.coord_x = x;
    ubicacion.coord_y = y;
    ubicaciones.alta(ubicacion);
}

void Ciudad::demoler_edificio(int x, int y)
{
    mapa[x][y]->demoler();
}

bool Ciudad::guardar_ubicaciones()
{
    ofstream ubicaciones_out;
    ubicaciones_out.open("ubicaciones.txt");

    if(ubicaciones_out.is_open()){
        for (int i = 1; i < ubicaciones.mostrar_cantidad() + 1; i++){
            ubicaciones_out << ubicaciones[i].nombre << " "
                            << "(" << ubicaciones[i].coord_x << ", "
                            << ubicaciones[i].coord_y << ")" << endl;
            }
        return true;
    }
    else
        return false;
}

void Ciudad::demoler_todo()
{
    for(int i = 1; i < ubicaciones.mostrar_cantidad()+1;i++)
        mapa[ubicaciones[i].coord_x ][ubicaciones[i].coord_y]->demoler();
}

void Ciudad::mostrar_ubicaciones()
{
    Lista<Ubicacion> copia; 
    Lista<Ubicacion> auxiliar;
    int cant = 1;

    for(int i = 1; i < ubicaciones.mostrar_cantidad()+1; i++ )
        copia.alta(ubicaciones[i]);

    for(int i = 1; i < copia.mostrar_cantidad()+1; i++ ){
        auxiliar.alta(copia[i]);
        for(int j = i+1; j < copia.mostrar_cantidad()+1; j++ ){
            if(auxiliar[1].nombre == copia[j].nombre){
                auxiliar.alta(copia[j]);
                cant++;
                copia.baja(j);
                --j;
            }
        }
        cout << cant << '\t'
             << auxiliar[1].nombre << '\t';
        for(int i = 1; i < auxiliar.mostrar_cantidad()+1; i++ ){
            cout << auxiliar[i].coord_x << ' ' 
                 << auxiliar[i].coord_y << '\t';
        }
        cout << endl;
        cant = 1;
        while (! auxiliar.vacia())
            auxiliar.baja(1);
    }
}