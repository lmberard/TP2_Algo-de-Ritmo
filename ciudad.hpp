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

    Lista<Provision> provisiones;
    Lista<Ubicacion> ubicaciones;

    int filas;
    int columnas;
    Casillero ***mapa;

    public:
        Ciudad();
        Ciudad(const string &,const string &, const string &,Terreno & terreno,Constructor & bob, Recurso & recurso);
        ~Ciudad();

        void mostrar_mapa();

        void consultar_coordenada(int , int );
     
        void construir(int ,int ,const string &, Constructor & bob );

        void cargar_ubicaciones(Constructor & bob);

        bool chequear_permisos_edificio(const string & edificio, Constructor & bob);

        bool chequear_stock(Edificio * edificio, bool);

        void cargar_ubicaciones(const string& PATH);

        void cargar_provisiones(const string & PATH, Recurso & recurso);

        void mostrar_inventario();

        void agregar_ubicacion(int x,int y,string edificio);

        void demoler_edificio(int x, int y); 

        bool guardar_ubicaciones();

        void demoler_todo();

        void mostrar_ubicaciones();

        int construidos(const string &);

        void recolectar();

        void guardar_materiales();

        void quitar_ubicacion(int x,int y);

        void lluvia(Recurso &){
            //tener un atributo que sea coordenadas transitables y cargarlo
            //para esto habría que generar en casillero una funcion del tipo bool
            //que sea algo como CasilleroTransitable? si:no. o algo asi no se 
            //sacar un numero random para agarrar un par de coordenadas del vector 
            //instanciar un material con la clase recurso  
            //Borrar ese par de coordenadas para que no salga de nuevo 
            //Si se llenan todos los casilleros decir mensaje 
        }

};
