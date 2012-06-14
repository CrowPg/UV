#include <iostream>
#include "Rationnel.h"

QString Rationnel::afficher(){
    QString r = QString::number(num, 'g', 6);
    QString i = QString::number(den, 'g', 6);
    return r.append("/").append(i);
}

Rationnel& Rationnel::operator +=(Rationnel const &r){
    num*=r.den;
    num+=den*r.num;
    den*=r.den;
    return *this;
}

Rationnel& Rationnel::operator -(){
    num=-num;
    return *this;
}

Rationnel& Rationnel::operator -=(Rationnel const &r){
    //*this+=(-r); // pas sûr
    return *this;
}

Rationnel& Rationnel::operator *=(Rationnel const &r){
    num*=r.num;
    den*=r.den;
    return *this;
}

Rationnel& Rationnel::operator /=(Rationnel const &r){
    num*=r.den;
    den*=r.num;
}

Rationnel operator+(Rationnel const &r1, Rationnel const &r2);
Rationnel operator-(Rationnel const &r1, Rationnel const &r2);
Rationnel operator*(Rationnel const &r1, Rationnel const &r2);
Rationnel operator/(Rationnel const &r1, Rationnel const &r2);

Rationnel operator+(Rationnel const &r1, Rationnel const &r2){
    Rationnel r(r1);
    r+=r2;
    return r;
}

Rationnel operator-(Rationnel const &r1, Rationnel const &r2){
    Rationnel r(r1);
    r-=r2;
    return r;
}

Rationnel operator*(Rationnel const &r1, Rationnel const &r2){
    Rationnel r(r1);
    r*=r2;
    return r;
}

Rationnel operator/(Rationnel const &r1, Rationnel const &r2){
    Rationnel r(r1);
    r/=r2;
    return r;
}

Rationnel& Rationnel::operator =(Rationnel const &r){
    num=r.num;
    den=r.den;
    return *this;
 }
