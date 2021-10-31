#ifndef EDIFICIO_H
#define EDIFICIO_H

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

        Edificio(string n, int s, int w, int m, int p):nombre(n),piedra(s),madera(w),metal(m),permitidos(p){};

        virtual string mostrar() = 0;
        virtual ~Edificio(){};

};

class Aserradero: public Edificio{

    public:

        Aserradero(string n, int s, int w, int m, int p): Edificio(n,s,w,m,p){};

        string mostrar()
        {return nombre;}
        ~Aserradero(){};
};

class Escuela: public Edificio{
    public:
        Escuela(string n , int s, int w, int m, int p): Edificio(n,s,w,m,p){};

        string mostrar()
        {return nombre;}
        ~Escuela(){};
};

class Yacimiento: public Edificio{
    public:
        Yacimiento(string n, int s, int w, int m, int p): Edificio(n,s,w,m,p){};

        string mostrar()
        {return nombre;}
        ~Yacimiento(){};
};

class Universidad: public Edificio{
    public:
        Universidad(string n, int s, int w, int m, int p): Edificio(n,s,w,m,p){};

        string mostrar()
        {return nombre;}
        ~Universidad(){};
};

class Supermercado: public Edificio{
    public:
        Supermercado(string n, int s, int w, int m, int p): Edificio(n,s,w,m,p){};

        string mostrar()
        {return nombre;}
        ~Supermercado(){};
};

#endif 