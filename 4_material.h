#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Material{
    string nombre;
    int cantidad;
    public: 
        virtual void mostrar_nombre() = 0;
        virtual string mostrar_cantidad() = 0;
      
};

class Madera: public Material{

  string nombre;
  int cantidad;

  public:

    Madera():nombre("Madera"),cantidad(60){}
    void mostrar_nombre()
    {cout << "Madera";}
    string mostrar_cantidad()
    {return "60";}

};