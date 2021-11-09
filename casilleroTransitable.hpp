#ifndef CASILLEROTRANSITABLE_HPP
#define CASILLEROTRANSITABLE_HPP
#include "casillero.hpp"

class CasilleroTransitable : public Casillero
{
    Material *material = 0;

public:
    // PRE:
    // POS:
    CasilleroTransitable();

    // PRE:
    // POS:
    ~CasilleroTransitable();

    // PRE:
    // POS:
    void mostrar();

    // PRE:
    // POS:
    void display();
    //bool agregar(Edificio *);

    // para la funcion de lluvia de materiales:

    /* void agregar_material(string nombre, int cantidad, Ciudad andypolis)
     {

         material = new Material(nombre, cantidad);
         andypolis.agregar_material(nombre, cantidad, material);
     }*/

     bool estransitable(){
         return true;
     }

     bool agregar(Material * material){
         if(this->material){
        cout << "ya hay un material aca" << endl;
        return NULL;
        }
        this->material = material;
        return true;
     }

     void demoler(){
        delete material;
        material = NULL;
    }
};

#endif // CASILLEROTRANSITABLE_HPP

