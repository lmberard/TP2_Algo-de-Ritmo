#ifndef CASILLEROINACCESIBLE_HPP
#define CASILLEROINACCESIBLE_HPP
#include "casillero.hpp"

class CasilleroInaccesible : public Casillero
{
public:
    // PRE: -
    // POS: se crea un casilleroInaccesible en la posicion (x,y)
    CasilleroInaccesible(int x, int y);

    // PRE: -
    // POS: se destruye el casilleroInaccesible
    ~CasilleroInaccesible();

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    void mostrar();

    // PRE: -
    // POS: Muestra por la terminal el tipo de casillero, sus coordenadas y su contenido
    void display();

    // LLUVIA DE RECURSOS------------------------------
    // PRE: -
    // POS: Se agrega un material en el casillero
    void agregar_material(string nombre, int cantidad);

    // RECOLECTAR MATERIALES --------------------------------------
    // PRE: -
    // POS: devuelve el material que construye (casilleroConstruible)
    string devolver_material_produccion();

    // PRE: -
    // POS: devuelve la cantidad del material que construye (casilleroConstruible)
    int devolver_cant_material_produccion();

    // CONSTRUIR / DESTRUIR EDIFICIO ------------------------------
    void agregar(Edificio *);
    // PRE: -
    // POS: agrega un edificio en el casillero (casilleroConstruible)
    void construir_edificio(string nombre);

    // PRE: -
    // POS: se destruye el edificio del casillero (casilleroConstruible)
    void destruir_edificio();
};

#endif // CASILLEROINACCESIBLE_HPP