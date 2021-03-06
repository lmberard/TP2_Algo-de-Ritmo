#include "casilleroTransitable.hpp"

CasilleroTransitable ::CasilleroTransitable(int x, int y) : Casillero(x, y)
{
}

CasilleroTransitable ::~CasilleroTransitable()
{
}

void CasilleroTransitable ::mostrar()
{
    cout << "Soy un casillero transitable y tengo " << this->material->obtener_cantidad() << " de "
         << this->material->obtener_nombre() << endl;
    cout << "estás en la posición " << this->coord_x << " " << this->coord_y << endl;
}

void CasilleroTransitable ::display()
{
    cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_LIGHT_GRAY_247 << "   " << END_COLOR << " ";
}

// para la funcion de lluvia de materiales:
/* void agregar_material(string nombre, int cantidad, Ciudad andypolis)
 {

     material = new Material(nombre, cantidad);
     andypolis.agregar_material(nombre, cantidad, material);
 }*/
