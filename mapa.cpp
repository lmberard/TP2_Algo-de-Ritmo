#include "mapa.hpp"

Mapa::Mapa()
{
    this->filas = 0;
    this->columnas = 0;
    this->mapa = 0;
}

void Mapa::cargar(const string &PATH)
{

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
    this->filas = stoi(filas_);
    this->columnas = stoi(columnas_);

    this->mapa = new Casillero **[filas];

    for (int i = 0; i < filas; i++)
    {
        this->mapa[i] = new Casillero *[columnas];
        for (int j = 0; j < columnas; j++)
        {
            archivo_mapa >> casillero;
            if (casillero == "L")
                this->mapa[i][j] = new CasilleroInaccesible(i, j);

            if (casillero == "T")
                this->mapa[i][j] = new CasilleroConstruible(i, j);

            if (casillero == "C")
                this->mapa[i][j] = new CasilleroTransitable(i, j);
        }
    }
}

Mapa::~Mapa()
{
    
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            delete mapa[i][j];

    for (int i = 0; i < filas; i++)
        delete[] this->mapa[i];

    delete[] this->mapa;
}

void Mapa::consultar_coordenada(int i, int j)
{
    this->mapa[i][j]->mostrar();
}

void Mapa::mostrar_mapa()
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            this->mapa[i][j]->display();
        }
        cout << endl;
    }
}

void Mapa::agregar_edificio(int x, int y, Edificio *edificio)
{
    //cout << "falta jeje" << endl;
     mapa[x][y]->agregar(edificio);
}

void Mapa::cargar_ubicaciones(const string& PATH){
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
