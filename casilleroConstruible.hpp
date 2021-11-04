#ifndef CASILLEROCONSTRUIBLE_HPP
#define CASILLEROCONSTRUIBLE_HPP
#include "casillero.hpp"

class CasilleroConstruible : public Casillero
{
    Edificio *edificio = 0;

public:
    // PRE:
    // POS: se crea un casillero construible en la posicion (x,y)
    CasilleroConstruible(int x, int y);

    // PRE:
    // POS: se destruye el casillero construible
    ~CasilleroConstruible();

    // PRE:
    // POS: se agrega un edificio en el casillero
    void agregar(Edificio *edificio);

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    void mostrar();

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    void display();

    // PRE: -
    // POS: devuelve el material que construye (casilleroConstruible)
    string devolver_material_produccion();

    // PRE: -
    // POS: devuelve la cantidad del material que construye (casilleroConstruible)
    int devolver_cant_material_produccion();

    // PRE: -
    // POS: el edificio del casillero apunta al objeto ya construido en la lista de edificios
    void construir_edificio(string nombre);

    // PRE: -
    // POS: el edificio del casillero apunta a null
    void destruir_edificio();

    // PRE: -
    // POS: agrega un material en el casillero (casilleroTransitable)
    void agregar_material(string nombre, int cantidad);
};
#endif // CASILLEROONSTRUIBLE_HPP