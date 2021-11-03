#include "parser.hpp"

void Parser::cargar(Lista<Edificio*> &edificios, const string &PATH)
{
    fstream archivo_edificios(PATH, ios::in);

    if (!archivo_edificios.is_open())
    {
        cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
        archivo_edificios.open(PATH, ios::out);
        archivo_edificios.close();
        archivo_edificios.open(PATH, ios::in);
    }

    string nombre, piedra, madera, metal, permitidos;
    while (archivo_edificios >> nombre)
    {

        archivo_edificios >> piedra;
        archivo_edificios >> madera;
        archivo_edificios >> metal;
        archivo_edificios >> permitidos;

        if (nombre == "aserradero")
            edificios.alta(new Aserradero(stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)));
        if (nombre == "fabrica")
            edificios.alta(new Fabrica(stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)));
        if (nombre == "escuela")
            edificios.alta(new Escuela(stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)));
        if (nombre == "yacimiento")
            edificios.alta(new Yacimiento(stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)));
        if (nombre == "mina")
            edificios.alta(new Mina(stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)));
        if (nombre == "obelisco")
            edificios.alta(new Obelisco(stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)));
        if (nombre == "planta")
            edificios.alta(new PlantaElectrica(stoi(piedra), stoi(madera), stoi(metal), stoi(permitidos)));
    }
}
/*
void Parser::cargar(Lista<Material*> &materiales, const string &PATH)
{
    fstream archivo_materiales(PATH, ios::in);

    if (!archivo_materiales.is_open())
    {
        cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
        archivo_materiales.open(PATH, ios::out);
        archivo_materiales.close();
        archivo_materiales.open(PATH, ios::in);
    }

    string nombre, cantidad;
    while (archivo_materiales >> nombre)
    {

        archivo_materiales >> cantidad;

        if (nombre == "piedra")
            materiales.alta(new Piedra(nombre, stoi(cantidad)), 1);
        if (nombre == "madera")
            materiales.alta(new Madera(nombre, stoi(cantidad)), 2);
        if (nombre == "metal")
            materiales.alta(new Metal(nombre, stoi(cantidad)), 3);
    }
*/
