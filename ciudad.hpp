#ifndef CIUDAD_HPP
#define CIUDAD_HPP
#include <iostream>
#include <string>
#include <fstream>
#include "colors.hpp"
/*#include "material.hpp"
#include "edificio.hpp"
#include "mapa.hpp"
#include "lista.hpp"
*/
class Ciudad
{
private:
    // Mapa mapa;
    //  Lista<Edificio> edificios;
    //  Lista<Material> materiales;
    //   Parser parser;

    int cant_edificios;
    int cant_materiales;

public:
    // LLUVIA DE RECURSOS
    // void recolectar_recursos();
    /*
        // CONSTUIR EDIFICIO
        void agregar_edificio(string nombre);
        void restar_materiales(string nombre, Edificio edificio);
        // void agregar_ubicacion();

        // DESTRUIR EDIFICIO
        void destruir_edificio(string nombre, Edificio edificio);
        void recolectar_materiales_reciclados(Edificio edificio);
        // void eliminar_ubicacion();

        // LLUVIA DE MATERIALES
        void agregar_material(string nombre, int cantidad);*/
};

#endif // CIUDAD_HPP