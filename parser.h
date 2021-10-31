#include <iostream>
#include <string>
#include <fstream>
#include "listas.h"

using namespace std;

class Parser{

    public: 
        void cargar(Lista<Edificio> &edificios, const string & PATH){
            fstream archivo_edificios(PATH, ios::in);

            if(!archivo_edificios.is_open()){
                cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
                archivo_edificios.open(PATH, ios::out);
                archivo_edificios.close();
                archivo_edificios.open(PATH, ios::in);
            }

            string nombre, piedra, madera,metal, permitidos;
            while(archivo_edificios >> nombre){
            
                archivo_edificios >> piedra;
                archivo_edificios >> madera;
                archivo_edificios >> metal;
                archivo_edificios >> permitidos;

                if(nombre == "aserradero")
                    edificios.alta(new Aserradero(nombre, stoi(piedra),stoi(madera),stoi(metal),stoi(permitidos)),1);
                if(nombre == "escuela")
                    edificios.alta(new Escuela(nombre, stoi(piedra),stoi(madera),stoi(metal),stoi(permitidos)),2);
                if(nombre == "yacimiento")
                    edificios.alta(new Yacimiento(nombre, stoi(piedra),stoi(madera),stoi(metal),stoi(permitidos)),3);
                if(nombre == "universidad")
                    edificios.alta(new Universidad(nombre, stoi(piedra),stoi(madera),stoi(metal),stoi(permitidos)),4);
                if(nombre == "supermercado")
                    edificios.alta(new Supermercado(nombre, stoi(piedra),stoi(madera),stoi(metal),stoi(permitidos)),5);
            }
        }

        void cargar(Lista<Material> &materiales, const string & PATH){
            fstream archivo_materiales(PATH, ios::in);

            if(!archivo_materiales.is_open()){
                cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
                archivo_materiales.open(PATH, ios::out);
                archivo_materiales.close();
                archivo_materiales.open(PATH, ios::in);
            }

            string nombre, cantidad;
            while(archivo_materiales >> nombre){
            
                archivo_materiales >> cantidad;

                if(nombre == "piedra")
                    materiales.alta(new Piedra(nombre, stoi(cantidad)),1);
                if(nombre == "madera")
                    materiales.alta(new Madera(nombre, stoi(cantidad)),2);
                if(nombre == "metal")
                    materiales.alta(new Metal(nombre, stoi(cantidad)),3);
            }
        }
};