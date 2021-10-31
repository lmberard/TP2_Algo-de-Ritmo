#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Material{

    protected:
    string nombre;
    int cantidad;
    public: 

        Material(string n, int cant):nombre(n),cantidad(cant){};
        virtual string mostrar() = 0;
    virtual ~Material(){};
};

class Madera: public Material{

  public:

    Madera(string n, int cant): Material(n,cant){};
    string mostrar()
    {return nombre;}
    ~Madera(){};

};

class Piedra: public Material{

  public:

    Piedra(string n, int cant): Material(n,cant){};
    string mostrar()
    {return nombre;}
    ~Piedra(){};

};

class Metal: public Material{

  public:

    Metal(string n, int cant): Material(n,cant){};
    string mostrar()
    {return nombre;}
    ~Metal(){};
};


#endif