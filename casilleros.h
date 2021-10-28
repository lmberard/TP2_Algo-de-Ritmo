#include <iostream>
#include <string>
#include <fstream>
#include "colors.h"

using namespace std;

class Material
{
    string nombre = "Madera";
    int cantidad = 60;

public:
    string mostrar_nombre()
    {
        return nombre;
    }
    int mostrar_cantidad()
    {
        return cantidad;
    }
};
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
    virtual void agregar_material(Material){};
};

class CasilleroConstruible : public Casillero
{

public:
    void mostrar()
    {
        cout << "Soy un casillero construible" << endl;
        cout << "estás en la posición " << coord_x << " " << coord_y << endl;
    }
    void display() { cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_GREEN_2 << "   " << END_COLOR << " "; } //"T"
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
