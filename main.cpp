#include <iostream>
#include <string>
#include <fstream>
#include "mapa.h"

using namespace std;
/*
class Material{
    string nombre = "Madera";
    int cantidad = 60;
    public: 
        string mostrar_nombre()
        {return nombre;}
        int mostrar_cantidad()
        {return cantidad;}
};

class Casillero{
  protected:
    int coord_x, coord_y;
  public:
   void set_coordenadas(int x,int y)
   {coord_x = x; coord_y = y;}
   virtual void mostrar() = 0; 
   virtual void agregar_material(Material){};
};

class CasilleroConstruible: public Casillero {
  public:
    void mostrar()
      { cout << "Soy un casillero construible" << endl;
        cout << "estás en la posición " << coord_x << " " << coord_y << endl;}
};



class Edificio{
    string nombre = "aserradero";
    public: 
        string mostrar_nombre()
        {return nombre;}
};

class CasilleroTransitable: public Casillero{
  Material material;
  public:
    void mostrar()
    { cout << "Soy un casillero transitable y tengo " << material.mostrar_cantidad() << " de "
    << material.mostrar_nombre() << endl;
    cout << "estás en la posición " << coord_x << " " << coord_y << endl;}
};

class CasilleroInaccesible: public Casillero{
    public:
        void mostrar()
        {cout << "Soy un casillero inaccesible y estás en la posición "<< coord_x << " " << coord_y << endl;}
};
*/


int main (){

  //Casillero *mapa[2][2];

  Mapa mapa(8,10);

  mapa.cargar();

  mapa.display();

/*
  CasilleroConstruible casillero_construible;
  CasilleroInaccesible casillero_inaccesible;
  CasilleroTransitable casillero_transitable;

  int filas = 5;
  int columnas = 5;
  
  Casillero* **mapa;
  mapa = new Casillero**[filas];
  for (int i = 0; i < filas; i++){
		mapa[i] = new Casillero*[columnas];
    for(int j = 0; j < columnas; j++){
			mapa[i][j] = &casillero_construible;
      mapa[i][j]->set_coordenadas(i,j);
      mapa[i][j]->mostrar();
    }
	}
   for (int i = 0; i < filas; i++){
    for(int j = 0; j < columnas; j++){
      mapa[i][j]->mostrar();
    }
	}
  for (int i = 0; i < filas; i++)
	    delete [] mapa[i];

  delete[] mapa;
*/
/*
  mapa[0][0] = new CasilleroConstruible;
  mapa[0][0]->set_coordenadas(0,0);

  mapa[1][0] = new CasilleroInaccesible;
  mapa[1][0]->set_coordenadas(1,0);

  
  mapa[2][0] = new CasilleroTransitable;
  mapa[2][0]->set_coordenadas(2,0);

  mapa[0][0]->mostrar();
  mapa[1][0]->mostrar();
  mapa[2][0]->mostrar();

  delete mapa[0][0];
  delete mapa[1][0];
  delete mapa[2][0];
*/
  return 0;
}