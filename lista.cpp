#include "lista.hpp"

template <class Dato>
Lista::Lista()
{
    this->primero = 0;
    this->cantidad = 0;
}

// PRE: 1 <= pos <= cantidad + 1
// POS: agrega d arriba de la pila e incrementa tope en 1
void Lista::alta(Dato *d, int pos)
{
    Nodo<Dato *> *nuevo = new Nodo<Dato *>(d);
    std::cout << "Pido memoria en: " << nuevo << std::endl;
    Nodo<Dato *> *siguiente = primero;

    if (pos == 1)
    {
        this->primero = nuevo;
    }
    else
    {
        Nodo<Dato *> *anterior = obtener_nodo(pos - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
}

// PRE: 1 <= pos <= cantidad
// POS: devuelve el dato que esta arriba
Dato *Lista::consulta(int pos)
{
    Nodo<Dato *> *aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

// PRE: 1 <= pos <= cantidad
// POS: devuelve el dato que esta arriba y decrementa tope
void Lista::baja(int pos)
{
    Nodo<Dato *> *baja = primero;
    if (pos == 1)
        primero = baja->obtener_siguiente();
    else
    {
        Nodo<Dato *> *anterior = obtener_nodo(pos - 1);
        baja = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(baja->obtener_siguiente());
    }
    cantidad--;
    std::cout << "Libero memoria en: " << baja << std::endl;

    delete baja;
}

// PRE: -
// POS: devuelve true si la pila esta vacia, false si no
bool Lista::vacia()
{
    return (cantidad == 0);
}

// Destructor
Lista::~Lista()
{
    while (!vacia())
        baja(1);
}
