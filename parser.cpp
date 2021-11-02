#include "parser.hpp"

void Parser::cargar(Lista<Edificio> &edificios)
{
    fstream archivo_edificios(PATH_EDIFICIOS, ios::in);

    if (!archivo_edificios.is_open())
    {
        cout << "No se encontro un archivo con nombre \"" << PATH_EDIFICIOS << "\", se va a crear el archivo" << endl;
        archivo_edificios.open(PATH_EDIFICIOS, ios::out);
        archivo_edificios.close();
        archivo_edificios.open(PATH_EDIFICIOS, ios::in);
    }

    string nombre, piedra, madera, metal, permitidos;
    while (archivo_edificios >> nombre)
    {

        archivo_edificios >> piedra;
        archivo_edificios >> madera;
        archivo_edificios >> metal;
        archivo_edificios >> permitidos;
        /*
                if (nombre == "aserradero")
                    edificios.alta(new EdificioAserradero(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)), 1);
                if (nombre == "escuela")
                    edificios.alta(new EdificioEscuela(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)), 2);
                if (nombre == "mina")
                    edificios.alta(new EdificioMina(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)), 3);
                // revisar planta electrica
                if (nombre == "planta")
                    edificios.alta(new EdificioPlantaElectrica(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)), 4);
                if (nombre == "obelisco")
                    edificios.alta(new EdificioObelisco(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)), 5);
                if (nombre == "fabrica")
                    edificios.alta(new EdificioFabrica(nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)), 6);
                    */
    }
}

void Parser::cargar(Lista<Material> &materiales)
{
    fstream archivo_materiales(PATH_MATERIALES, ios::in);

    if (!archivo_materiales.is_open())
    {
        cout << "No se encontro un archivo con nombre \"" << PATH_MATERIALES << "\", se va a crear el archivo" << endl;
        archivo_materiales.open(PATH_MATERIALES, ios::out);
        archivo_materiales.close();
        archivo_materiales.open(PATH_MATERIALES, ios::in);
    }

    string nombre, cantidad;
    while (archivo_materiales >> nombre)
    {

        archivo_materiales >> cantidad;
    }
}

void Parser::cargar(Lista<Ubicacion> &ubicaciones)
{
    /*    ifstream archivo_entrada(PATH_UBICACIONES);

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

        }
        else
        {
            cout << "Error. No existe el archivo de ubicaciones.txt" << endl;

        }
    */
}