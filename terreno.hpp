#include "casillero.hpp"
#include "casilleroTransitable.hpp"
#include "casilleroInaccesible.hpp"
#include "casilleroConstruible.hpp"

class Terreno{
    
    public:
        Casillero* agregar(const string casillero_tipo){
            Casillero* casillero;
            if (casillero_tipo == "L")
                casillero = new CasilleroInaccesible();

            if (casillero_tipo == "T")
                casillero =  new CasilleroConstruible();

            if (casillero_tipo == "C")
                casillero =  new CasilleroTransitable();

            return casillero;
        }  
};