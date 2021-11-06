#include "recurso.hpp"


Material * Recurso::dar_material(const string & material){
    Material* elemento;

    if(material == "piedra")
        elemento = new Piedra;
    if(material == "madera")
        elemento = new Madera;
    if(material == "metal")
        elemento = new  Metal;

    return elemento;
}