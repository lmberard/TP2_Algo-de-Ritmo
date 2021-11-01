#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>
#include "nodo.hpp"

template <class Dato>
class Lista
{
    // Atributos
private:
    Nodo<Dato *> *primero;
    int cantidad;

    // Metodos
public:
    // Constructor
    // PRE: -
    // POS: tope = 0
    Lista();

    // PRE: 1 <= pos <= cantidad + 1
    // POS: agrega d arriba de la pila e incrementa tope en 1
    void alta(Dato *d, int pos);

    // PRE: 1 <= pos <= cantidad
    // POS: devuelve el dato que esta arriba
    Dato *consulta(int pos);

    // PRE: 1 <= pos <= cantidad
    // POS: devuelve el dato que esta arriba y decrementa tope
    void baja(int pos);

    // PRE: -
    // POS: devuelve true si la pila esta vacia, false si no
    bool vacia();

    // Destructor
    ~Lista();

private:
    Nodo<Dato *> *obtener_nodo(int pos)
    {
        Nodo<Dato *> *aux = primero;
        for (int i = 1; i < pos; i++)
            aux = aux->obtener_siguiente();
        return aux;
    }
};

#endif // LISTA_HPP
