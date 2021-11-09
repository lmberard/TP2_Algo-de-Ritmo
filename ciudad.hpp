#ifndef CIUDAD_HPP
#define CIUDAD_HPP

#include "colors.hpp"
#include "ubicaciones.hpp"
#include "lista.hpp"


#include "terreno.hpp"
#include "constructor.hpp"
#include "recurso.hpp"
#include "inventario.hpp"

class Ciudad{

    Inventario inventario;

    Lista<Ubicacion> ubicaciones;
    Lista<Ubicacion> materiales;

    int filas;
    int columnas;
    Casillero ***mapa;

    Lista<Ubicacion> coordenadasTransitables;

    public:
        Ciudad();
        Ciudad(const string &,const string &, const string &,Terreno & terreno,Constructor & bob, Recurso & recurso);
        ~Ciudad();

        void mostrar_mapa();

        void consultar_coordenada(int , int );
     
        void construir(int ,int ,const string &, Constructor & bob );

        void cargar_ubicaciones(Constructor & bob);

        bool chequear_permisos_edificio(const string & edificio, Constructor & bob);

        void cargar_ubicaciones(const string& PATH);

        void mostrar_inventario();

        void agregar_ubicacion(int x,int y,string edificio);

        void demoler_edificio(int x, int y); 

        bool guardar_ubicaciones();

        void demoler_todo();

        void mostrar_ubicaciones();

        int construidos(const string &);

        void recolectar();

        void quitar_ubicacion(int x,int y);
        
        void llenarcoordenadatransitable();

        void lluvia(Recurso & recurso);
};

void listar_edificios(Ciudad & andypolis, Constructor & bob);

#endif //CIUDAD_HPP