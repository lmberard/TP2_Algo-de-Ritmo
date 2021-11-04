#include "casilleroInaccesible.hpp"

CasilleroInaccesible ::CasilleroInaccesible(int x, int y) : Casillero(x, y)
{
}

CasilleroInaccesible ::~CasilleroInaccesible()
{
}

void CasilleroInaccesible ::mostrar()
{
    cout << "Soy un casillero inaccesible y estás en la posición " << this->coord_x << " " << this->coord_y << endl;
}

void CasilleroInaccesible ::display()
{
    cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_BLUE_25 << "   " << END_COLOR << " ";
}

void CasilleroInaccesible ::agregar_material(string nombre, int cantidad)
{
    cout << "No se puede agregar material en este casillero" << endl;
}

string CasilleroInaccesible ::devolver_material_produccion()
{
    return "Este casillero no produce materiales";
}

int CasilleroInaccesible ::devolver_cant_material_produccion()
{
    // cout << "No hay materiales producidos en este casillero" << endl;
    return 0;
}

void CasilleroInaccesible ::agregar(Edificio *)
{
    cout << "No se puede construir un edificio en este casillero" << endl;
}

void CasilleroInaccesible ::construir_edificio(string nombre)
{
    cout << "No se puede construir un edificio en este casillero" << endl;
}

void CasilleroInaccesible ::destruir_edificio()
{
    cout << "No se puede construir ni destruir un edificio en este casillero" << endl;
}