#include "constructor.hpp"

Constructor::Constructor(){}

void Constructor::cargar(const string & PATH)
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

Edificio * Constructor::construye(const string & edificio){

    Edificio * construido = NULL;

    if(edificio == "yacimiento")
        construido = new Yacimiento(edificios[buscar_edificio(edificio)]);
    if(edificio == "aserradero")
        construido = new Aserradero(edificios[buscar_edificio(edificio)]);
    if(edificio == "escuela")
        construido = new Escuela(edificios[buscar_edificio(edificio)]);
    if(edificio == "fabrica")
        construido = new Fabrica(edificios[buscar_edificio(edificio)]);
    if(edificio == "mina")
        construido = new Mina(edificios[buscar_edificio(edificio)]);
    if(edificio == "obelisco")
        construido = new Obelisco(edificios[buscar_edificio(edificio)]);
    if(edificio == "planta electrica")
        construido = new PlantaElectrica(edificios[buscar_edificio(edificio)]);

    return construido;
}

int Constructor::buscar_edificio(string edificio)
{
    int i = 1;
       
    int cantidad = edificios.mostrar_cantidad();
    while(cantidad && (edificios[i]->obtener_nombre() != edificio)){
        i++;
        --cantidad;
    }
        
    return i;
}

void Constructor::borrar()
{

	for(int i = 1; i < edificios.mostrar_cantidad()+1; i++ ){
        delete edificios[i];
    }
}