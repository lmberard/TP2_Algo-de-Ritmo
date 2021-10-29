#ifndef CASILLEROS_H
#define CASILLEROS_H

#include <iostream>
#include <string>
#include <fstream>
#include "colors.h"
#include "material.h"
#include "edificios.h"
#include "ciudad.h"

using namespace std;

class Casillero
{

protected:
    int coord_x = 0, coord_y = 0;

public:
    void set_coordenadas(int x, int y)
    {
        coord_x = x;
        coord_y = y;
    }
    virtual void mostrar() = 0;
    virtual void display() = 0;
    // virtual void agregar_material(Ciudad andypolis) = 0;
    // virtual void agregar_edificio(Ciudad andypolis) = 0;
};

class CasilleroConstruible : public Casillero
{
    Edificio edificio;

public:
    void mostrar()
    {
        cout << "Soy un casillero construible" << endl;
        cout << "estás en la posición " << coord_x << " " << coord_y << endl;
    }
    void display() { cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_GREEN_2 << "   " << END_COLOR << " "; } //"T"

    void construir_edificio(Ciudad andypolis, string nombre)
    {
        andypolis.agregar_edificio(nombre);
        andypolis.restar_materiales(nombre, edificio);
        // andypolis.agregar_coordenada();
    }

    void destruir_edificio(Ciudad andypolis, string nombre, Edificio edificio)
    {
        andypolis.destruir_edificio(nombre, edificio);
        andypolis.recolectar_materiales_reciclados(edificio);
        // andypolis.eliminar_coordenada()
    }
};

class CasilleroTransitable : public Casillero
{
    Material material;

public:
    void mostrar()
    {
        cout << "Soy un casillero transitable y tengo " << material.mostrar_cantidad() << " de "
             << material.mostrar_nombre() << endl;
        cout << "estás en la posición " << coord_x << " " << coord_y << endl;
    }
    void display() { cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_LIGHT_GRAY_247 << "   " << END_COLOR << " "; } //"C"

    // para la funcion de lluvia de materiales:
    void agregar_material(string nombre, int cantidad, Ciudad andypolis)
    {

        material = new Material(nombre, cantidad);
        andypolis.agregar_material(nombre, cantidad, material);
    }
};

class CasilleroInaccesible : public Casillero
{
public:
    void mostrar()
    {
        cout << "Soy un casillero inaccesible y estás en la posición " << coord_x << " " << coord_y << endl;
    }
    void display() { cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_BLUE_25 << "   " << END_COLOR << " "; } //"L"
};

#endif // CASILLEROS.H