#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Edificio{

    protected:

        string nombre;
        
        int piedra;
        int madera;
        int metal;

        int permitidos;

      

    public:

        Edificio(){};

        virtual string mostrar() = 0;

};

class Aserradero: public Edificio{
    public:
        string mostrar()
        {return "aserradero";}
};

class Escuela: public Edificio{
    public:
        string mostrar()
        {return "escuela"; }
};

class Yacimiento: public Edificio{
    public:
        string mostrar()
        {return "yacimiento";}
};

class Universidad: public Edificio{
    public:
        string mostrar()
        {return "Universidad";}
};

class Supermercado: public Edificio{
    public:
        string mostrar()
        {return "supermercado";}
};

