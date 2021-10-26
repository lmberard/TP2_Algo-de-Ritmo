#include <iostream>
#include <string>
#include <fstream>
#include "casilleros.h"

class Mapa{
    
    int filas;
    int columnas;
  
    Casillero* **mapa;

    CasilleroConstruible casillero_construible;
    CasilleroInaccesible casillero_inaccesible;
    CasilleroTransitable casillero_transitable;

    public: 

    Mapa(int x, int y){

        filas = x;
        columnas = y; 

        mapa = new Casillero**[filas];

        for (int i = 0; i < filas; i++){
		    mapa[i] = new Casillero*[columnas];
            /*for(int j = 0; j < columnas; j++){
			    mapa[i][j] = &casillero_construible;
                mapa[i][j]->set_coordenadas(i,j);
            }*/
	    }
    } 
        
    void cargar(){
        for (int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
			    mapa[i][j] = &casillero_construible;
                mapa[i][j]->set_coordenadas(i,j);
            }
	    }
    }
    ~Mapa(){ 
        for (int i = 0; i < filas; i++)
	        delete [] mapa[i];

        delete[] mapa;
    }

    void mostrar(){
         for (int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                mapa[i][j]->mostrar();
            }
         }
	}

     void display(){
         for (int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                mapa[i][j]->display();
            }
            cout << endl;
         }
	}
};


