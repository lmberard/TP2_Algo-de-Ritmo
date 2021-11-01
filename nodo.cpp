#include "nodo.hpp"
template <class Dato>
Nodo::Nodo(Dato d)
{
    this->dato = d;
    this->siguiente = 0;
}

void Nodo::cambiar_dato(Dato d)
{
    this->dato = d;
}

void Nodo::cambiar_siguiente(Nodo *pn)
{
    this->siguiente = pn;
}

Dato Nodo::obtener_dato()
{
    return this->dato;
}

Nodo *Nodo::obtener_siguiente()
{
    return this->siguiente;
}

Nodo::~Nodo()
{
    // delete dato;
}