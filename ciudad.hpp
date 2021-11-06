#include "colors.hpp"
#include "ubicaciones.hpp"
#include "lista.hpp"

#include "terreno.hpp"
#include "constructor.hpp"
#include "recurso.hpp"

struct Provision{
    Material* material;
    int cantidad;
};

class Ciudad{

    Terreno terreno;
    Constructor bob;
    Recurso recurso;

    Lista<Provision> provisiones;
    Lista<Ubicacion> ubicaciones;

    int filas;
    int columnas;
    Casillero ***mapa;

    public:
        Ciudad();
        Ciudad(const string &);
        ~Ciudad();

        void mostrar_mapa();

        void consultar_coordenada(int , int );
     
        void construir(int ,int ,const string & );

        void cargar_ubicaciones();

        bool chequear_permisos_edificio(const string & edificio);

        bool chequear_stock(Edificio * edificio);

        void cargar_ubicaciones(const string& PATH);

        void cargar_provisiones(const string & PATH);

        void mostrar_inventario();

        void agregar_ubicacion(int x,int y,string edificio);

        void demoler_edificio(int x, int y); 

        bool guardar_ubicaciones();

        void demoler_todo();

        void mostrar_ubicaciones();
};