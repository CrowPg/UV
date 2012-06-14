#ifndef Nombres_Header_h
#define Nombres_Header_h

#include "Constante.h"
#include "Rationnel.h"

class Entier : public Constante{
    int val;

public:
    Entier(int v):val(v){}

    QString afficher(){
        return QString::number(val);
    }

    int getVal(){
        return val;
    }

    Entier& operator+=(Entier const &n);
    Entier& operator-();
    Entier& operator-=(Entier const &n);
    Entier& operator*=(Entier const &n);
    Entier& operator/=(Entier const &n);
    Entier& operator =(Entier const &n);
};

Entier operator +(Entier const &n1, Entier const &n2);
Entier operator -(Entier const &n1, Entier const &n2);
Entier operator *(Entier const &n1, Entier const &n2);
Entier operator /(Entier const &n1, Entier const &n2);

#endif
