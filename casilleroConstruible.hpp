#ifndef CASILLEROCONSTRUIBLE_HPP
#define CASILLEROCONSTRUIBLE_HPP
#include "casillero.hpp"

class CasilleroConstruible : public Casillero
{
    Edificio *edificio = 0;

public:
    // PRE:
    // POS:
    CasilleroConstruible(int x, int y);

    // PRE:
    // POS:
    ~CasilleroConstruible();

    // PRE:
    // POS:
    void agregar(Edificio *edificio);

    // PRE:
    // POS:
    void mostrar();

    // PRE:
    // POS:
    void display();
    /*
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
        }*/
};
#endif // CASILLEROONSTRUIBLE_HPP
