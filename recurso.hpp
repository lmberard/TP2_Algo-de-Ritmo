#include "lista.hpp"

#include "material.hpp"
#include "materialMadera.hpp"
#include "materialMetal.hpp"
#include "materialPiedra.hpp"

class Recurso{

    public:
     Material* dar_material(const string & material);
};