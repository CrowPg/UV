#ifndef Nombres_Rationnel_h
#define Nombres_Rationnel_h

#include "Constante.h"
#include "Reel.h"
#include "Entier.h"

class Rationnel : public Constante{
    int num;
    int den;

public:
    Rationnel(int n, int d) {
        num=n;
        den=d;
    }

    int getNum(){
        return num;
    }
    int getDen(){
        return den;
    }

    int getVal(){
        return 0;
    }

    void setDen(int n){
        den=n;
    }

    QString afficher();

    Rationnel& operator +=(Rationnel const &r);
    Rationnel& operator -();
    Rationnel& operator -=(Rationnel const &r);
    Rationnel& operator *=(Rationnel const &r);
    Rationnel& operator /=(Rationnel const &r);
    Rationnel& operator =(Rationnel const &r);
};

Rationnel operator+(Rationnel const &r1, Rationnel const &r2);
Rationnel operator-(Rationnel const &r1, Rationnel const &r2);
Rationnel operator*(Rationnel const &r1, Rationnel const &r2);
Rationnel operator/(Rationnel const &r1, Rationnel const &r2);

#endif
