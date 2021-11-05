#ifndef MAPA_HPP
#define MAPA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include "casillero.hpp"
#include "casilleroTransitable.hpp"
#include "casilleroInaccesible.hpp"
#include "casilleroConstruible.hpp"
#include "edificio.hpp"
#include "lista.hpp"
#include "ubicaciones.hpp"

class Mapa
{

    int filas;
    int columnas;

    Casillero ***mapa;
    //Ubicacion ubicaciones[80];
    Lista<Ubicacion> ubicaciones;

public:
    // PRE:
    // POS:
    Mapa();

    // PRE:
    // POS:
    void cargar(const string &);

    // PRE:
    // POS:
    ~Mapa();

    // PRE:
    // POS:
    void consultar_coordenada(int, int);

    // PRE:
    // POS:
    void mostrar_mapa();

    // PRE:
    // POS:
    void agregar_edificio(int, int, Edificio *);


    void cargar_ubicaciones(const string& PATH);

    void mostrar_ubicaciones(){
        Lista<Ubicacion> copia; 
        Lista<Ubicacion> auxiliar;
        int cant = 1;

        for(int i = 1; i < ubicaciones.mostrar_cantidad()+1; i++ )
            copia.alta(ubicaciones[i]);

        for(int i = 1; i < copia.mostrar_cantidad()+1; i++ ){
            auxiliar.alta(copia[i]);
            for(int j = i+1; j < copia.mostrar_cantidad()+1; j++ ){
                if(auxiliar[1].nombre == copia[j].nombre){
                    auxiliar.alta(copia[j]);
                    cant++;
                    copia.baja(j);
                    --j;
                }
            }
            cout << cant << '\t'
                 << auxiliar[1].nombre << '\t';
            for(int i = 1; i < auxiliar.mostrar_cantidad()+1; i++ ){
                cout << auxiliar[i].coord_x << ' ' 
                     << auxiliar[i].coord_y << '\t';
            }
            cout << endl;
            cant = 1;
            while (! auxiliar.vacia())
                auxiliar.baja(1);
        }
    }

    void demoler_edificio(int x, int y){
        mapa[x][y]->demoler();
    }

    Ubicacion devolver_ubicacion(int i){
        return ubicaciones[i];
    }

    int cant_edificios(){
        return ubicaciones.mostrar_cantidad();
    }

};

#endif // MAPA_HPP
