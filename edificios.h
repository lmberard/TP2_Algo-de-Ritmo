#ifndef EDIFICIOS_H
#define EDIFICIOS_H

#include <iostream>
#include <string>
#include <fstream>
#include "colors.h"
#include "material.h"

const int MINA_CANT_MATERIAL_PROD = 15;
const string MINA_MATERIAL_PROD = "piedra";

const int ASERRADERO_CANT_MATERIAL_PROD = 25;
const string ASERRADERO_MATERIAL_PROD = "madera";

const int FABRICA_CANT_MATERIAL_PROD = 40;
const string FABRICA_MATERIAL_PROD = "metal";

const int ESCUELA_CANT_MATERIAL_PROD = 0;
const string ESCUELA_MATERIAL_PROD = "No brinda materiales";

const int OBELISCO_CANT_MATERIAL_PROD = 0;
const string OBELISCO_MATERIAL_PROD = "No brinda materiales";

const int PLANTA_ELECTRICA_CANT_MATERIAL_PROD = 0;
const string PLANTA_ELECTRICA_MATERIAL_PROD = "No brinda materiales";

class Edificio
{

protected:
    string nombre;
    int piedra;
    int madera;
    int metal;
    int cant_construido;
    int cant_max_construida;
    int cant_mat_que_produce;
    string mat_que_produce;
    // Ubicacion *posiciones_construidos;

public:
    string obtener_nombre() { return nombre; }
    int obtener_madera() { return madera; }
    int obtener_metal() { return metal; }
    int obtener_cant_construido() { return cant_construido; }
    int obtener_cant_mat_producido() { return cant_mat_que_produce; }
    string obtener_mat_producido() { return mat_que_produce; }
    void modificar_cant_construido(int cantidad) { cant_construido += cantidad }
    void mostrar_edificio()
    {
        cout << TXT_UNDERLINE << "TIPO DE EDIFICIO:" << END_COLOR << " " + nombre << endl;
        cout << "\tCantidad de piedra: " << to_string(piedra) << endl;
        cout << "\tCantidad de madera: " << to_string(madera) << endl;
        cout << "\tCantidad de metal: " << to_string(metal) << endl;
        cout << "\tCantidad construido hasta el momento: " << to_string(cant_construidos) << endl;
        cout << "\tMaterial que produce: " << mat_que_produce << endl;
        cout << "\tCantidad de material que produce: " << to_string(cant_mat_que_produce) << endl;
        cout << "\tCuantas unidades más se pueden construir sin superar el limite: " << to_string(cant_max_construida - cant_construido) << endl;
        cout << endl;
    }
    virtual void setear_material_que_produce() = 0;
    // virtual void agregar_posicion_construido();
    /*cuando leo ubicaciones.txt y para cuand*/
    // virtual void eliminar_posicion_construido(); /*esto seria cuando se destruye un edificio*/

}

class EdificioMina : public Edificio
{
public:
    void setear_material_que_produce()
    {
        cant_mat_producido = MINA_CANT_MATERIAL_PROD;
        mat_producido = MINA_MATERIAL_PROD;
    }
}

class EdificioAserradero : public Edificio
{
public:
    void setear_material_que_produce()
    {
        cant_mat_producido = ASERRADERO_CANT_MATERIAL_PROD;
        mat_producido = ASERRADERO_MATERIAL_PROD;
    }

}

class EdificioFabrica : public Edificio
{
public:
    void setear_material_que_produce()
    {
        cant_mat_producido = FABRICA_CANT_MATERIAL_PROD;
        mat_producido = FABRICA_MATERIAL_PROD;
    }
}

class EdificioEscuela : public Edificio
{

public:
    void setear_material_que_produce()
    {
        cant_mat_producido = ESCUELA_CANT_MATERIAL_PROD;
        mat_producido = ESCUELA_MATERIAL_PROD;
    }
}

class EdificioObelisco : public Edificio
{
public:
    void setear_material_que_produce()
    {
        cant_mat_producido = ESCUELA_CANT_MATERIAL_PROD;
        mat_producido = ESCUELA_MATERIAL_PROD;
    }

}

class EdificioPlantaElectrica : public Edificio
{
public:
    void setear_material_que_produce()
    {
        cant_mat_producido = PLANTA_ELECTRICA_CANT_MATERIAL_PROD;
        mat_producido = PLANTA_ELECTRICA_MATERIAL_PROD;
    }
}

#endif // EDIFICIOS_H