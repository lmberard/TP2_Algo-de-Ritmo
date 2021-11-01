#ifndef NODO_HPP
#define NODO_HPP
#include <iostream>
#include <string>
#include <fstream>
template <class Dato>
class Nodo
{

private:
    Dato dato;
    Nodo *siguiente;

public:
    // PRE:
    // POS:
    Nodo(Dato d);

    // PRE:
    // POS:
    void cambiar_dato(Dato d);

    // PRE:
    // POS:
    void cambiar_siguiente(Nodo *pn);

    // PRE:
    // POS:
    Dato obtener_dato();

    // PRE:
    // POS:
    Nodo *obtener_siguiente();

    // PRE:
    // POS:
    ~Nodo();
};

#endif // NODO_HPP