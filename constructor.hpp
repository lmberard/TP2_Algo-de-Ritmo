#include "lista.hpp"

#include "edificio.hpp"

#include "edificioAserradero.hpp"
#include "edificioEscuela.hpp"
#include "edificioYacimiento.hpp"
#include "edificioObelisco.hpp"
#include "edificioMina.hpp"
#include "edificioFabrica.hpp"
#include "edificioPlantaElectrica.hpp"

class Constructor{
    Lista<Edificio*> edificios;
        int buscar_edificio(string edificio);
    public: 
        Constructor();
        void cargar(const string &PATH);
        Lista<Edificio*>  lista();
        void borrar();
        Edificio * construye(const string & edificio);
};