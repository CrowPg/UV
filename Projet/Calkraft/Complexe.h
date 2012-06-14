#ifndef Nombres_Complexe_h
#define Nombres_Complexe_h

#include "Constante.h"

class Complexe : public Constante{
    double re;
    double im;

public:
    Complexe(double r, double i) : re(r), im(i) {}

    double getRe(){
        return re;
    }

    double getIm(){
        return im;
    }


    QString afficher();
    Complexe& operator +=(Complexe const &r);
    Complexe& operator -();
    Complexe& operator -=(Complexe const &r);
    Complexe& operator *=(Complexe const &r);
    Complexe& operator /=(Complexe const &r);
    Complexe& operator =(Complexe const &c);
};

Complexe operator+(Complexe const &r1, Complexe const &r2);
Complexe operator-(Complexe const &r1, Complexe const &r2);
Complexe operator*(Complexe const &r1, Complexe const &r2);
Complexe operator/(Complexe const &r1, Complexe const &r2);

#endif
