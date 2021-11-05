#ifndef CIUDAD_HPP
#define CIUDAD_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //para generar random numbers
#include "colors.hpp"
#include "material.hpp"
#include "edificio.hpp"
#include "mapa.hpp"
#include "ubicaciones.hpp"
#include "lista.hpp"
#include "parser.hpp"

// Para la lluvia de materiales
const int CANT_MAX_RANDOM_MADERA = 0;
const int CANT_MIN_RANDOM_MADERA = 1;
const int CANT_MAX_RANDOM_METAL = 2;
const int CANT_MIN_RANDOM_METAL = 4;
const int CANT_MAX_RANDOM_PIEDRA = 1;
const int CANT_MIN_RANDOM_PIEDRA = 2;

const int CANT_TIPOS_DE_EDIFICIOS = 6;

class Ciudad
{
private:
    Mapa mapa;
    Lista<Edificio *> edificios;
    Lista<Material *> materiales;
    Parser parser;

public:
    // CONSTRUCTOR-DESTRUCTOR--------------------------
    // PRE:
    // POST: Se procesaron los archivos de mapa.txt, materiales.txt, ubicaciones.txt y mapa.txt y se guardaron en las listas.
    void procesar_archivos();
    // PRE:
    // POST: se construye la instancia de Ciudad con listas vacias y cantidades=0
    // Ciudad();
    // PRE:
    // POST: se destruyen las listas, clases y la instancia de Ciudad.
    ~Ciudad();

    // FUNCIONES DEL MENU PRINCIPAL--------------------
    // PRE:
    // POST: Se construye un edificio segun su nombre y coordenadas en el mapa. Se modifica la cantidad de materiales que se usaron y se agrega a la lista de ubicaciones
    // void construir_edificio(string nombre, int x, int y);

    // PRE:
    // POST: ??
    // void listar_edificios_construidos();

    // PRE:
    // POST: Se recorre la lista de edificios y se muestra por la terminal con sus respectivos atributos
    void listar_edificios();

    // PRE:
    // POST: se elimina un edificio segun su nombre y coordenadas del mapa. Se recolectan los materiales reciclados, se agregan a la lista y se elimina la ubicacion de la lista de ubicaciones
    void demoler_edificio(int x, int y);

    // PRE:
    // POST: se recorre el mapa y se muestra por la terminal todos los casillero coloreados segun el tipo de casillero y lo que contienen (material o edificio)
    void mostrar_mapa();

    // PRE:
    // POST: se imprime por la terminal que tipo de casillero es ese y que tiene adentro (material/edificio)
    void consultar_coordenada(int x, int y);

    // LISTAR TODOS LOS CONSTRUIDOS
    // PRE:
    // POST: se recorre la lista de materiales y se muestran por la terminal con su respectiva cantidad
    void mostrar_inventario();

    // PRE:
    // POST:
    int buscar_edificio(string edificio);

    // PRE:
    // POST:
    void chequear_stock(int i);

    // PRE:
    // POST:
    void construir(int x, int y, string edificio);

    // PRE:
    // POST:
    void cargar_ubicaciones();

    // PRE:
    // POST:
    void mostrar_ubicaciones();

    // PRE:
    // POST: se recolectan los recursos producidos de los edificios construidos y se guardan en la lista de materiales
    void recolectar_recursos();

    // PRE:
    // POST: se crean materiales nuevos aleatoriamente y se colocan en los casilleros transitorios y luego se guardan en la lista de materiales(opcional?)
    void lluvia_recursos();

    // PRE:
    // POST: se guarda lo de la lista de edificios, materiales y ubicaciones en sus archivos txt
    void guardar_archivos();

    bool guardar_ubicaciones();

    bool guardar_materiales();
};

#endif // CIUDAD_HPP