#ifndef NODO_HPP
#define NODO_HPP
#include <iostream>
#include <string>
#include <fstream>

// typedef int Dato;

template <class Dato>
class Nodo
{
    // Atributos
private:
    Dato dato;
    Nodo *siguiente;

    // Metodos
public:
    // constructor
    // PRE:
    // POS:
    Nodo(Dato d)
    {
        dato = d;
        siguiente = 0;
    }

    // PRE:
    // POS:
    void cambiar_dato(Dato d)
    {
        dato = d;
    }

    // PRE:
    // POS:
    void cambiar_siguiente(Nodo *pn)
    {
        siguiente = pn;
    }

    // PRE:
    // POS:
    Dato obtener_dato()
    {
        return dato;
    }

    // PRE:
    // POS:
    Nodo *obtener_siguiente()
    {
        return siguiente;
    }

    /*~Nodo(){
        delete dato;
    }*/
};

#endif // NODO_HPP