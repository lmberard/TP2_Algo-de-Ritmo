#include "casillero.hpp"

Casillero::Casillero(){}

bool Casillero::agregar(Edificio *)
{
    cout << "No puedes construir en este casillero" << endl;
    return NULL;
}

string Casillero::obtener_material(){
    return "C";
}

int Casillero::obtener_cantidad(){
    return 0;
}

Edificio* Casillero::mostrar_edificio(){
    return NULL;
}
