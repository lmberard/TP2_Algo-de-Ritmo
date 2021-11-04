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

string CasilleroTransitable ::devolver_material_produccion()
{
    // cout << "No hay materiales producidos en este casillero" << endl;
    return "Este casillero no produce materiales";
}

// PRE: -
// POS: devuelve la cantidad del material que construye (casilleroConstruible)
int CasilleroTransitable ::devolver_cant_material_produccion()
{
    // cout << "No hay materiales producidos en este casillero" << endl;
    return 0;
}

// CONSTRUIR / DESTRUIR EDIFICIO ------------------------------
void CasilleroTransitable ::agregar(Edificio *)
{
    cout << "No se puede agregar un edificio en este casillero" << endl;
}
// PRE: -
// POS: agrega un edificio en el casillero (casilleroConstruible)
void CasilleroTransitable ::construir_edificio(string nombre)
{
    cout << "No se puede construir un edificio en este casillero" << endl;
}

// PRE: -
// POS: se destruye el edificio del casillero (casilleroConstruible)
void CasilleroTransitable ::destruir_edificio()
{
    cout << "No se puede construir ni destruir un edificio en este casillero." << endl;
}
