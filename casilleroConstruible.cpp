#include "casilleroConstruible.hpp"

CasilleroConstruible ::CasilleroConstruible(int x, int y) : Casillero(x, y)
{
}

CasilleroConstruible ::~CasilleroConstruible()
{
}

void CasilleroConstruible ::agregar(Edificio *edificio)
{
    this->edificio = edificio;
}

void CasilleroConstruible ::mostrar()
{
    cout << "Soy un casillero construible" << endl;
    cout << "estás en la posición " << this->coord_x << " " << this->coord_y << endl;
    if (this->edificio)
    {
        cout << "Tengo construido este edificio:" << endl;
        this->edificio->mostrar_edificio();
    }
}

void CasilleroConstruible ::display()
{
    cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_GREEN_2 << "   " << END_COLOR << " ";
}
string CasilleroConstruible ::devolver_material_produccion()
{
    return this->edificio->obtener_mat_producido();
}

int CasilleroConstruible ::devolver_cant_material_produccion()
{
    return this->edificio->obtener_cant_mat_producido();
}

void CasilleroConstruible ::construir_edificio(string nombre) // Lista<Edificio> *edificios
{
    /* APUNTO this->edificio al objeto edificio que este en la lista de edificios ya construido
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

void CasilleroConstruible ::destruir_edificio()
{
    this->edificio = 0;
}

void CasilleroConstruible ::agregar_material(string nombre, int cantidad)
{
    cout << "No se puede agregar material en este casillero" << endl;
}