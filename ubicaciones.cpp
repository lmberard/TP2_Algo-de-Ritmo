
#include "ubicaciones.hpp"
/*
int main()
{
    Ubicacion ubicaciones[MAX];
    inicializar_vector(ubicaciones);
    if (procesar_ubicaciones(ubicaciones))
    {
        imprimir_ubicaciones(ubicaciones);
    }
    else
        cout << "No se leyo bien el archivo" << endl;

    ubicaciones[4].nombre = "hola";
    ubicaciones[4].coord_x = 50;
    ubicaciones[4].coord_y = 100;

    if (guardar_ubicaciones(ubicaciones))
    {
        cout << "Cambios guardados" << endl;
    }
    else
        cout << "No se guardo bien el archivo" << endl;

    return 0;
}
*/
bool procesar_ubicaciones(Ubicacion ubicaciones[MAX])
{
    ifstream archivo_entrada(PATH_UBICACIONES);

    if (archivo_entrada)
    {

        string nombre, aux, coord_x, coord_y;
        int i = 0;

        while (getline(archivo_entrada, nombre, ' '))
        {
            if (nombre != "planta")
            {
                ubicaciones[i].nombre = nombre;
                getline(archivo_entrada, aux, '(');

                getline(archivo_entrada, coord_x, ',');
                ubicaciones[i].coord_x = stoi(coord_x);

                getline(archivo_entrada, aux, ' ');
                getline(archivo_entrada, coord_y, ')');
                ubicaciones[i].coord_y = stoi(coord_y);
                getline(archivo_entrada, aux);
            }
            else
            {

                getline(archivo_entrada, aux, ' ');
                ubicaciones[i].nombre = nombre + " " + aux;

                getline(archivo_entrada, aux, ' ');

                getline(archivo_entrada, coord_x, ',');
                ubicaciones[i].coord_x = stoi(coord_x);

                getline(archivo_entrada, aux, ' ');
                getline(archivo_entrada, coord_y, ')');
                ubicaciones[i].coord_y = stoi(coord_y);
                getline(archivo_entrada, aux);
            }

            i++;
        }

        archivo_entrada.close();
        return true;
    }
    else
    {
        cout << "Error. No existe el archivo de ubicaciones.txt" << endl;
        return false;
    }
}

bool guardar_ubicaciones(Ubicacion ubicaciones[MAX])
{
    ofstream ubicaciones_out;
    ubicaciones_out.open(PATH_UBICACIONES);
    string separador = " ";
    string vacio = " ";
    size_t i = 0;

    if (ubicaciones_out.is_open())
    {
        i = 0;
        while (ubicaciones[i].nombre != vacio)
        {
            ubicaciones_out << ubicaciones[i].nombre;
            ubicaciones_out << separador << "(" << ubicaciones[i].coord_x;
            ubicaciones_out << "," << separador << ubicaciones[i].coord_y;
            ubicaciones_out << ")" << endl;
            i++;
        }
        ubicaciones_out.close();
        cout << "Se guardaron los cambios en el archivo ubicaciones.txt" << endl;
        return true;
    }
    else
        return false;
}

void imprimir_ubicaciones(Ubicacion ubicaciones[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        if (ubicaciones[i].nombre != " ")
        {
            cout << "Tipo de edificio:" << ubicaciones[i].nombre << endl;
            cout << "Coordenada x: " << ubicaciones[i].coord_x << endl;
            cout << "Coordenada y: " << ubicaciones[i].coord_y << endl
                 << endl;
        }
        else
            return;
    }
}

void inicializar_vector(Ubicacion ubicaciones[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        ubicaciones[i].nombre = " ";
        ubicaciones[i].coord_x = 0;
        ubicaciones[i].coord_y = 0;
    }
}