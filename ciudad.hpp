#ifndef CIUDAD_HPP
#define CIUDAD_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> //para generar random numbers
#include "colors.hpp"
#include "material.hpp"
#include "edificio.hpp"
#include "mapa.hpp"
#include "ubicaciones.hpp"
#include "lista.hpp"
#include "parser.hpp"

// Para la lluvia de materiales
const int CANT_MAX_RANDOM_MADERA = 0;
const int CANT_MIN_RANDOM_MADERA = 1;
const int CANT_MAX_RANDOM_METAL = 2;
const int CANT_MIN_RANDOM_METAL = 4;
const int CANT_MAX_RANDOM_PIEDRA = 1;
const int CANT_MIN_RANDOM_PIEDRA = 2;

const int CANT_TIPOS_DE_EDIFICIOS = 6;

class Ciudad
{
private:

    Mapa mapa;
    Lista<Edificio*> edificios;
    Lista<Material*> materiales;
    Parser parser;

    //int cant_edificios;
    //int cant_materiales;
    //int cant_ubicaciones;

public:
    // CONSTRUCTOR-DESTRUCTOR--------------------------
    // PRE:
    // POST: Se procesaron los archivos de mapa.txt, materiales.txt, ubicaciones.txt y mapa.txt y se guardaron en las listas.
    void procesar_archivos();
    // PRE:
    // POST: se construye la instancia de Ciudad con listas vacias y cantidades=0
   // Ciudad();
    // PRE:
    // POST: se destruyen las listas, clases y la instancia de Ciudad.
    ~Ciudad();

    // FUNCIONES DEL MENU PRINCIPAL--------------------
    // PRE:
    // POST: Se construye un edificio segun su nombre y coordenadas en el mapa. Se modifica la cantidad de materiales que se usaron y se agrega a la lista de ubicaciones
    //void construir_edificio(string nombre, int x, int y);

    // PRE:
    // POST: ??
   // void listar_edificios_construidos();

    // PRE:
    // POST: Se recorre la lista de edificios y se muestra por la terminal con sus respectivos atributos
    void listar_edificios();

    // PRE:
    // POST: se elimina un edificio segun su nombre y coordenadas del mapa. Se recolectan los materiales reciclados, se agregan a la lista y se elimina la ubicacion de la lista de ubicaciones
    void demoler_edificio(int x, int y){
        mapa.demoler_edificio(x,y);
    }

    // PRE:
    // POST: se recorre el mapa y se muestra por la terminal todos los casillero coloreados segun el tipo de casillero y lo que contienen (material o edificio)
    void mostrar_mapa();

    // PRE:
    // POST: se imprime por la terminal que tipo de casillero es ese y que tiene adentro (material/edificio)
    void consultar_coordenada(int x, int y);

    // PRE:
    // POST: se recorre la lista de materiales y se muestran por la terminal con su respectiva cantidad
    void mostrar_inventario();

    // PRE:
    // POST: se recolectan los recursos producidos de los edificios construidos y se guardan en la lista de materiales
    //void recolectar_recursos();

    // PRE:
    // POST: se crean materiales nuevos aleatoriamente y se colocan en los casilleros transitorios y luego se guardan en la lista de materiales(opcional?)
    //void lluvia_recursos();

    // PRE:
    // POST: se guarda lo de la lista de edificios, materiales y ubicaciones en sus archivos txt
    //void guardar_archivos();

    // FUNCIONES AUXILIARES----------------------------

    /////// LLUVIA DE RECURSOS
    // POST: se agrega el material y su cantidad en el casillero de coordenada (x,y) y en la lista de materiales
    //void agregar_material_en_coordenada(string nombre_material, int cantidad, int x, int y);

    /////// CONSTRUIR EDIFICIO
    // PRE:
    // POST: Construye los edificios de la lista de ubicaciones
    //void inicializar_mapa();
    // PRE:
    // POST: construye el edificio en la coordenada (x,y)
    //void agregar_edificio(string nombre_edificio, int x, int y);
    // PRE:
    // POST: resta los materiales necesarios para la construccion segun el nombre del edificio y los elimina de la lista de materiales
    //void restar_materiales_construccion(string nombre_edificio);
    // PRE:
    // POST: se agrega la ubicacion del edificio en la lista de ubicaciones segun su nombre y coordenada
    //void agregar_ubicacion(string nombre_edificio, int x, int y);
    // PRE:
    // POST: se agrega la ubicacion del edificio en la lista de ubicaciones segun lo que hay en el casillero
    //void agregar_ubicacion_contenido_casillero();

    /////// DESTRUIR EDIFICIO
    // PRE:
    // POST: se destruye el edificio segun el nombre y coordenadas
    //void destruir_edificio(string nombre_edificio, int x, int y);
    // PRE:
    // POST: se recolecta la mitad de los materiales utilizados para construir ese edificio.
    //void recolectar_materiales_reciclados(string nombre_edificio);
    // PRE:
    // POST: se elimina la ubicacion de la lista de ubicaciones
    //void eliminar_ubicacion(string nombre_edificio, int x, int y);

    int buscar_edificio(string edificio){
        int i = 1;
       
        int cantidad = edificios.mostrar_cantidad();
        while(cantidad && (edificios[i]->obtener_nombre() != edificio)){
            i++;
            --cantidad;
        }
        
        return i;
    }

    void chequear_stock(int i){
        int cuenta = 0;
        for(int j = 1; j < materiales.mostrar_cantidad()+1; j++ ){
            if(materiales[j]->obtener_nombre() == "Piedra"){  
                cuenta = materiales[j]->obtener_cantidad() - edificios[i]->obtener_piedra();
                if(cuenta < 0 ){
                    cout << "falta " << materiales[j]->obtener_nombre() << endl;
                    //flag = 0;
                }
                else
                    materiales[j]->modificar_cantidad(cuenta);
            }
            if(materiales[j]->obtener_nombre() == "Madera"){
                cuenta = materiales[j]->obtener_cantidad() - edificios[i]->obtener_madera();
                if(cuenta < 0 ){
                    cout << "falta " << materiales[j]->obtener_nombre() << endl;
                    //flag = 0;
                }
                else
                    materiales[j]->modificar_cantidad(cuenta);
            }
            if(materiales[j]->obtener_nombre() == "Metal"){
                cuenta = materiales[j]->obtener_cantidad() - edificios[i]->obtener_metal();
                if(cuenta < 0 ){
                    cout << "falta " << materiales[j]->obtener_nombre() << endl;
                    //flag = 0;
                }
                else
                    materiales[j]->modificar_cantidad(cuenta);
            }
        }
    }

    void construir(int x, int y, string edificio){      
        
        chequear_stock(buscar_edificio(edificio));
        //chequear_casillero()

        if(edificio == "yacimiento")
            mapa.agregar_edificio(x,y, new Yacimiento(edificios[buscar_edificio(edificio)]));
        if(edificio == "aserradero")
            mapa.agregar_edificio(x,y, new Aserradero(edificios[buscar_edificio(edificio)]));
        if(edificio == "escuela")
            mapa.agregar_edificio(x,y, new Escuela(edificios[buscar_edificio(edificio)]));
        if(edificio == "fabrica")
            mapa.agregar_edificio(x,y, new Fabrica(edificios[buscar_edificio(edificio)]));
        if(edificio == "mina")
            mapa.agregar_edificio(x,y, new Mina(edificios[buscar_edificio(edificio)]));
        if(edificio == "obelisco")
            mapa.agregar_edificio(x,y, new Obelisco(edificios[buscar_edificio(edificio)]));
        if(edificio == "planta electrica")
            mapa.agregar_edificio(x,y, new PlantaElectrica(edificios[buscar_edificio(edificio)]));
    }

    void cargar_ubicaciones(){
        Ubicacion edificio; 
        for(int i = 1; i < mapa.cant_edificios()+1;i++){
            edificio = mapa.devolver_ubicacion(i);
            construir(edificio.coord_x, edificio.coord_y, edificio.nombre);
        }
    }

    void mostrar_ubicaciones(){
        mapa.mostrar_ubicaciones();
    }
    
};


#endif // CIUDAD_HPP