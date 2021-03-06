#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <bits/stdc++.h>
#include "colors.hpp"
#include "mapa.hpp"

const int OPCION_MINIMA = 1;
const int OPCION_MAXIMA = 10;

const int CONSTRUIR_EDIFICIO = 1;
const int LISTAR_CONSTRUIDOS = 2;
const int LISTAR_TODOS = 3;
const int DEMOLER_POR_COORDENADA = 4;
const int MOSTRAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR_RECURSOS = 8;
const int LLUVIA_RECURSOS = 9;
const int SALIR = 10;

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif // __linux__

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif // __MINGW32__

// pre: -
// post: Imprime por pantalla las intrucciones sobre el formato y nombre de los archivos.txt a utilizar
void mostrar_InstruccionInicial();

// pre: -
// post: Imprime por pantalla el menu
void mostrar_menu();

// pre: -
// post: Pregunta para volver al menu
void volver();

// pre: El texto ingresado por el usuario tiene que ser un NUMERO entero
// post: Realiza la opcion pedida
void procesar_opcion(int opcion_elegida, Mapa &andypolis); // material *materiales_array, edificio *edificios_array, casillero **mapa, ubicacion *ubicaciones_array

// pre: El texto ingresado por el usuario tiene que ser un NUMERO entero
// post: devuelve true si la opcion recibida esta en el rango valido y sino devuelve false.
bool es_opcion_valida(int elegida);

// pre: -
// post: Obtiene una respuesta del usuario y la devuelve en minusculas.
string devolver_rta_usuario();

// pre: Existen los archivos txt correspondientes
// post: se muestra el menu Principal
void mostrar_menuInicial(Mapa &andypolis);

// pre: -
// post: se verifica que lo ingresado sea una opcion dentro del rango del menu.
void validar_opcion(int option_elegida, Mapa &andypolis);

#endif // MENU_H
