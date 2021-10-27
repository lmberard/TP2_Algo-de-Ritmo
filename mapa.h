#include <iostream>
#include <string>
#include <fstream>
#include "casilleros.h"

class Mapa{
    
    int filas;
    int columnas;
  
    Casillero* **mapa;

    public: 

        Mapa():filas(0),columnas(0),mapa(0){}
        Mapa(const string &);
        ~Mapa();

        void consultar_coordenada(int, int);
        void mostrar_mapa();
};

Mapa::Mapa(const string & PATH){

    fstream archivo_mapa(PATH, ios::in);

    if(!archivo_mapa.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
        archivo_mapa.open(PATH, ios::out);
        archivo_mapa.close();
        archivo_mapa.open(PATH, ios::in);
    }

    string casillero, filas_, columnas_;

    archivo_mapa >> filas_;
    archivo_mapa >> columnas_;
    filas = stoi(filas_);
    columnas = stoi(columnas_);

    mapa = new Casillero**[filas];

    for (int i = 0; i < filas; i++){
		mapa[i] = new Casillero*[columnas];
        for(int j = 0; j < columnas; j++){
            archivo_mapa >> casillero;
            if(casillero == "L"){
                mapa[i][j] = new CasilleroInaccesible;
                mapa[i][j]->set_coordenadas(i,j);
            }
            if(casillero == "T"){
			    mapa[i][j] = new CasilleroConstruible;
                mapa[i][j]->set_coordenadas(i,j);
            }
            if(casillero == "C"){
			    mapa[i][j] = new CasilleroTransitable;
                mapa[i][j]->set_coordenadas(i,j);
            }
        }
	}
}

Mapa::~Mapa(){ 

    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
	        delete mapa[i][j];

    for (int i = 0; i < filas; i++)
	    delete [] mapa[i];

    delete[] mapa;
}

Mapa::void consultar_coordenada(int i, int j){
    mapa[i][j]->mostrar();
}

Mapa::void mostrar_mapa(){
    for (int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            mapa[i][j]->display();
        }
        cout << endl;
    }
}