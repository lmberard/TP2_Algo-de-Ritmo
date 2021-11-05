#include "ciudad.hpp"

// CONSTRUCTOR-DESTRUCTOR--------------------------
// FALTA REVISAR PARSER
void Ciudad::procesar_archivos()
{   
    mapa.cargar("mapa.txt");
    mapa.cargar_ubicaciones("ubicaciones.txt");
    parser.cargar(edificios, "edificios.txt");
    parser.cargar(materiales, "materiales.txt");
    cargar_ubicaciones();
}

void Ciudad::mostrar_mapa(){
    mapa.mostrar_mapa();
}

void Ciudad::listar_edificios(){
      for(int i = 1; i < edificios.mostrar_cantidad()+1; i++ ){
           cout << edificios[i]->obtener_nombre() << '\t'
                << edificios[i]->obtener_madera() << '\t'
                << edificios[i]->obtener_metal()  << '\t'
                << edificios[i]->obtener_piedra() << '\t'
                << edificios[i]->obtener_cant_max() << '\t'
                << edificios[i]->obtener_cant_max() << '\t' //ESTO HABRIA QUE RESTARLO CON CUANTOS HAY YA
                << edificios[i]->obtener_cant_mat_producido() << ' '
                << edificios[i]->obtener_mat_producido()    
                << endl;
    }
}

void Ciudad::mostrar_inventario(){
    for(int i = 1; i < materiales.mostrar_cantidad()+1; i++ ){
           cout << materiales[i]->obtener_nombre() << '\t'
                << materiales[i]->obtener_cantidad() << ' ' 
                << endl;
    }
}

Ciudad::~Ciudad(){
     parser.borrar(edificios);
     parser.borrar(materiales);
}

void Ciudad::consultar_coordenada(int x,int y){
    mapa.consultar_coordenada(x,y);
}
