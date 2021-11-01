
#include "ciudad.hpp"
/*
// para la funcion de CONSTRUIR edificio por nombre y coordenada
void Ciudad::agregar_edificio(string nombre)
{

    Edificio edificio = new Edificio(nombre); // falta armar esto

    // modificar lista de edificios: AGREGAR_EDIFICIO
    for (int i = 0; i < this->cant_edificios; i++)
    {
        if (edificio.nombre == this->edificios[i].nombre)
        {
            this->edificios[i].modificar_cant_construido(1);
            this->edificios[i].agregar_coordenada(coord_x, coord_y);
        }
    }
}

void Ciudad::restar_materiales(string nombre, Edificio edificio)
{
    for (int i = 0; i < this->cant_materiales; i++)
    {
        if (this->materiales[i].nombre == "piedra")
            this->materiales[i].modificar_cantidad(-edificio.piedra);
        if (this->materiales[i].nombre == "madera")
            this->materiales[i].modificar_cantidad(-edificio.madera);
        if (this->materiales[i].nombre == "metal")
            this->materiales[i].modificar_cantidad(-edificio.metal);
    }
}

// para la funcion de DEMOLER edificio por nombre y coordenada
void Ciudad::destruir_edificio(string nombre, Edificio edificio)
{
    // modificar lista de edificios
    for (int i = 0; i < cant_edificios; i++)
    {
        if (edificio.nombre == this->edificios[i].nombre)
        {
            this->edificios[i].modificar_cant_construido(-1);
            this->edificios[i].eliminar_coordenada(coord_x, coord_y);
        }
    }
    // eliminar el edificio
    delete edificio;
}

void Ciudad::recolectar_materiales_reciclados(Edificio edificio)
{
    for (int i = 0; i < this->cant_materiales; i++)
    {
        if (this->materiales[i].nombre == "piedra")
            this->materiales[i].modificar_cantidad(edificio.piedra / 2);
        if (this->materiales[i].nombre == "madera")
            this->materiales[i].modificar_cantidad(edificio.madera / 2);
        if (this->materiales[i].nombre == "metal")
            this->materiales[i].modificar_cantidad(edificio.metal / 2);
    }
}

void Ciudad::agregar_material(string nombre, int cantidad, Material material)
{
    for (int i = 0; i < this->cant_materiales; i++)
    {
        if (material.nombre == this->materiales[i].nombre)
            this->materiales[i].modificar_cantidad(cantidad);
    }
}*/