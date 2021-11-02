#include "edificio.hpp"

Edificio::Edificio(string n, int s, int w, int m, int p)
{
    this->nombre = n;
    this->piedra = s;
    this->madera = w;
    this->metal = m;
    this->cant_max_construccion = p;
    // this->mat_que_produce = "";
    // this->cant_mat_que_produce = 0;
}

string Edificio::obtener_nombre()
{
    return this->nombre;
}

int Edificio::obtener_madera()
{
    return this->madera;
}

int Edificio::obtener_metal()
{
    return this->metal;
}

int Edificio::obtener_piedra()
{
    return this->piedra;
}

int Edificio::obtener_cant_max()
{
    return this->cant_max_construccion;
}

int Edificio::obtener_cant_mat_producido()
{
    return this->cant_mat_que_produce;
}

string Edificio::obtener_mat_producido()
{
    return this->mat_que_produce;
}

void Edificio::mostrar_edificio()
{
    cout << TXT_UNDERLINE << "TIPO DE EDIFICIO:" << END_COLOR << " " + nombre << endl;
    cout << "\tCantidad de piedra: " << to_string(this->piedra) << endl;
    cout << "\tCantidad de madera: " << to_string(this->madera) << endl;
    cout << "\tCantidad de metal: " << to_string(this->metal) << endl;
    cout << "\tUnidad máxima de construccion: " << to_string(this->cant_max_construccion) << endl;
    cout << "\tMaterial que produce: " << this->mat_que_produce << endl;
    cout << "\tCantidad de material que produce: " << to_string(this->cant_mat_que_produce) << endl;
    cout << endl;
}