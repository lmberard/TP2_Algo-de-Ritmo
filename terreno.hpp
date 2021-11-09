#ifndef TERRENO_HPP
#define TERRENO_HPP

#include "casillero.hpp"
#include "casilleroTransitable.hpp"
#include "casilleroInaccesible.hpp"
#include "casilleroConstruible.hpp"

class Terreno{
    
    public:
        Casillero* agregar(const string casillero_tipo);
};

#endif //TERRENO_HPP