#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "lista.hpp"

class Inventario{


    private: 
        Lista<Material*> materiales1;

    public:
        Inventario(){};

        void cargar(const string & PATH,Recurso & recurso){
            fstream archivo_materiales(PATH, ios::in);

            if (!archivo_materiales.is_open()){
                cout << "No se encontro un archivo con nombre \"" << PATH << "\", se va a crear el archivo" << endl;
                archivo_materiales.open(PATH, ios::out);
                archivo_materiales.close();
                archivo_materiales.open(PATH, ios::in);
            }

            string nombre, cantidad;
            while (archivo_materiales >> nombre){
                archivo_materiales >> cantidad;
                materiales1.alta(recurso.dar_material(nombre,stoi(cantidad)));
            }
        }

        void mostrar_inventario(){
            for(int i = 1; i < materiales1.mostrar_cantidad()+1; i++ ){
            cout << materiales1[i]->obtener_nombre() << '\t'
                 << materiales1[i]->obtener_cantidad() << ' ' 
                 << endl;
            }
        }

        bool chequear_stock(Edificio * edificio, bool construir){
            int cuenta = 0;
            bool flag = 1;
        
            for(int j = 1; j < materiales1.mostrar_cantidad()+1; j++ ){
                if(materiales1[j]->obtener_nombre() == "piedra"){  
                    cuenta = materiales1[j]->obtener_cantidad() - edificio->obtener_piedra();
                if(cuenta < 0 ){
                    cout << "falta " << materiales1[j]->obtener_nombre() << endl;
                    flag = 0;
                }
                if(construir)
                    materiales1[j]->modificar_cantidad(cuenta);
                }
                if(materiales1[j]->obtener_nombre() == "madera"){
                    cuenta = materiales1[j]->obtener_cantidad() - edificio->obtener_madera();
                if(cuenta < 0 ){
                    cout << "falta " << materiales1[j]->obtener_nombre() << endl;
                    flag = 0;
                }
                if(construir)
                    materiales1[j]->modificar_cantidad(cuenta);
                }
                if(materiales1[j]->obtener_nombre() == "metal"){
                    cuenta = materiales1[j]->obtener_cantidad() - edificio->obtener_metal();
                if(cuenta < 0 ){
                    cout << "falta " << materiales1[j]->obtener_nombre() << endl;
                    flag = 0;
                }
                if(construir)
                    materiales1[j]->modificar_cantidad(cuenta);
                }
            }

            return flag;
        }   

        void llenar_stock(Edificio * edificio){
            int cuenta = 0;
            for(int j = 1; j < materiales1.mostrar_cantidad()+1; j++ ){
                if(materiales1[j]->obtener_nombre() == "piedra"){
                    cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_piedra()/2; 
                    materiales1[j]->modificar_cantidad(cuenta);
                }
                if(materiales1[j]->obtener_nombre() == "madera"){
                    cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_madera()/2; 
                    materiales1[j]->modificar_cantidad(cuenta);
                }
                if(materiales1[j]->obtener_nombre() == "metal"){
                    cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_metal()/2; 
                    materiales1[j]->modificar_cantidad(cuenta);
                }
            }
        }

        void agregar_al_inventario(Edificio * edificio){

            int cuenta;

            for(int j = 1; j < materiales1.mostrar_cantidad()+1; j++){
            if(edificio->obtener_mat_producido() == materiales1[j]->obtener_nombre()){
                cuenta = materiales1[j]->obtener_cantidad() + edificio->obtener_cant_mat_producido();
                materiales1[j]->modificar_cantidad(cuenta);  
            }
        }
        }

        ~Inventario(){
            ofstream archivo_materiales("materiales.txt");
                for(int i = 1; i < materiales1.mostrar_cantidad()+1; i++){
                    archivo_materiales << materiales1[i]->obtener_nombre() << ' ' << materiales1[i]->obtener_cantidad() << '\n';
                    delete materiales1[i];
                }
        }


};




#endif //INVENTARIO_HPP