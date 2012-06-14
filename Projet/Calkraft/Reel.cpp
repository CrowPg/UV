#include <iostream>
#include "Reel.h"

QString Reel::afficher(){
    return QString::number(val, 'g', 6);
}

Reel& Reel::operator +=(Reel const &r){
    val+=r.val;
    return *this;
}

Reel& Reel::operator -(){
    val=-val;
    return *this;
}

Reel& Reel::operator -=(Reel const &r){
    val-=r.val;
    return *this;
}

Reel& Reel::operator *=(Reel const &r){
    val*=r.val;
    return *this;
}

Reel& Reel::operator /=(Reel const &r){
    val/=r.val;
    return *this;
}

Reel operator+(Reel const &r1, Reel const &r2){
    Reel r(r1);
    r+=r2;
    return r;
}

Reel operator-(Reel const &r1, Reel const &r2){
    Reel r(r1);
    r-=r2;
    return r;
}

Reel operator*(Reel const &r1, Reel const &r2){
    Reel r(r1);
    r*=r2;
    return r;
}

Reel operator/(Reel const &r1, Reel const &r2){
    Reel r(r1);
    r/=r2;
    return r;
}

Reel& Reel::operator =(Reel const &n){
    val=n.val;
    return *this;
}
