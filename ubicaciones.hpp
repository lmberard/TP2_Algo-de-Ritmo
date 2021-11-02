#ifndef UBICACIONES_HPP
#define UBICACIONES_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string PATH_UBICACIONES_PRUEBA = "ubicaciones.txt";
const int MAX = 200;

struct Ubicacion
{
    string nombre;
    int coord_x;
    int coord_y;
};

bool procesar_ubicaciones(Ubicacion ubicaciones[MAX]);
void imprimir_ubicaciones(Ubicacion ubicaciones[MAX]);
void inicializar_vector(Ubicacion ubicaciones[MAX]);
bool guardar_ubicaciones(Ubicacion ubicaciones[MAX]);

#endif // UBICACIONES_HPP
