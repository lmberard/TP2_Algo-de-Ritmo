#include "casilleroTransitable.hpp"

CasilleroTransitable ::CasilleroTransitable() : Casillero()
{
    material = 0;
}

CasilleroTransitable ::~CasilleroTransitable() {}

void CasilleroTransitable ::mostrar()
{
    cout << "Soy un casillero transitable" << endl;
    if (material)
        cout << material->obtener_nombre() << endl;
}

void CasilleroTransitable ::display()
{
    if (!material)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_LIGHT_GRAY_247 << "   " << END_COLOR << " ";
    else
        cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_LIGHT_GRAY_247 << " " << material->obtener_codigo() << " " << END_COLOR << " ";
}

bool CasilleroTransitable ::agregar(Material *material)
{
    if (this->material)
    {
        cout << "ya hay un material aca" << endl;
        return false;
    }
    this->material = material;
    return true;
}

void CasilleroTransitable ::demoler()
{
    delete material;
    material = NULL;
}

bool CasilleroTransitable ::estransitable()
{
    return true;
}