#include "casilleroConstruible.hpp"

CasilleroConstruible ::CasilleroConstruible() : Casillero(){}

CasilleroConstruible ::~CasilleroConstruible(){}

bool CasilleroConstruible ::agregar(Edificio *edificio)
{
    if(this->edificio){
        cout << "ya hay un edificio aca" << endl;
        return NULL;
    }
    this->edificio = edificio;
    return true;
}

void CasilleroConstruible ::mostrar()
{
    cout << "Soy un casillero construible" << endl;
    //cout << "estás en la posición " << this->coord_x << " " << this->coord_y << endl;
    if (edificio)
        cout << edificio->obtener_nombre() << endl;
}

void CasilleroConstruible ::display()
{   
    if(!edificio)
        cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_GREEN_2 << "   " << END_COLOR << " ";
    else
        cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_GREEN_2 << " " << edificio->obtener_codigo() << " " << END_COLOR << " ";
}

string CasilleroConstruible::obtener_material(){
    return edificio->obtener_mat_producido();
}

int CasilleroConstruible::obtener_cantidad(){
    return edificio->obtener_cant_mat_producido();
}

Edificio * CasilleroConstruible::mostrar_edificio(){
    return edificio;
}
/*
    void CasilleroConstruible ::construir_edificio(Ciudad andypolis, string nombre)
    {
        andypolis.agregar_edificio(nombre);
        andypolis.restar_materiales(nombre, edificio);
        // andypolis.agregar_coordenada();
    }

    void CasilleroConstruible ::destruir_edificio(Ciudad andypolis, string nombre, Edificio edificio)
    {
        andypolis.destruir_edificio(nombre, edificio);
        andypolis.recolectar_materiales_reciclados(edificio);
        // andypolis.eliminar_coordenada()
    }*/

