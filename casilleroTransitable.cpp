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

void CasilleroTransitable ::agregar_material(string nombre, int cantidad) // Lista<Edificio> *edificios
{
    /*
    //APUNTO this->edificio al objeto edificio que este en la lista de edificios ya construido
    if(nombre == "aserradero")
        this->edificio = edificios->aserradero();
    if(nombre == "escuela")
        this->edificio = edificios->escuela();
    if(nombre == "fabrica")
        this->edificio = edificios->fabrica();
    if(nombre == "planta electrica")
        this->edificio = edificios->planta_electrica();
    if(nombre == "obelisco")
        this->edificio = edificios->obelisco();
    if(nombre == "mina")
        this->edificio = edificios->mina();
    */
}
