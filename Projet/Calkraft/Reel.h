#ifndef Nombres_Reel_h
#define Nombres_Reel_h

#include "Constante.h"
#include "Complexe.h"

class Reel : public Constante{
    double val;

public:
    Reel(double v):val(v){}

    int getVal(){
        return 0;
    }

    QString afficher();

    Reel& operator +=(Reel const &r);
    Reel& operator -();
    Reel& operator -=(Reel const &r);
    Reel& operator *=(Reel const &r);
    Reel& operator /=(Reel const &r);
    Reel& operator =(Reel const &r);
};

Reel operator+(Reel const &r1, Reel const &r2);
Reel operator-(Reel const &r1, Reel const &r2);
Reel operator*(Reel const &r1, Reel const &r2);
Reel operator/(Reel const &r1, Reel const &r2);

#endif
