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
    /*if (edificio)
        cout << edificio->mostrar() << endl;*/
}

void CasilleroConstruible ::display()
{
    cout << TXT_BLACK_16 << TXT_UNDERLINE << BGND_GREEN_2 << "   " << END_COLOR << " ";
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
