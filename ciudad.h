#ifndef CIUDAD_H
#define CIUDAD_H
#include <iostream>
#include <string>
#include <fstream>
#include "colors.h"
#include "material.h"
#include "edificios.h"

class Ciudad
{
private:
    Edificio *edificios;
    Material *materiales;
    // Ubicacion **ubicaciones;

    int cant_edificios;
    int cant_materiales;
    // int cant_ubicaciones;

public:
    // LLUVIA DE RECURSOS (deberia ir en mapa?)
    // void recolectar_recursos();

    // CONSTUIR EDIFICIO
    void agregar_edificio(string nombre);
    void restar_materiales(string nombre, Edificio edificio);
    // void agregar_ubicacion();

    // DESTRUIR EDIFICIO
    void destruir_edificio(string nombre, Edificio edificio);
    void recolectar_materiales_reciclados(Edificio edificio);
    // void eliminar_ubicacion();

    // LLUVIA DE MATERIALES
    void agregar_material(string nombre, int cantidad);
}

#endif // CIUDAD_H