#include "Complexe.h"

QString Complexe::afficher(){
    QString r = QString::number(re, 'g', 6);
    QString i = QString::number(im, 'g', 6);
    return r.append("$").append(i);
}

Complexe& Complexe::operator +=(Complexe const &r){
    re+=r.re;
    im+=r.im;
    return *this;
}

Complexe& Complexe::operator -(){
    re=-re;
    im=-im;
    return *this;
}

Complexe& Complexe::operator -=(Complexe const &r){
    re-=r.re;
    im-=-r.im;
    return *this;
}

Complexe& Complexe::operator *=(Complexe const &r){
    double temp(re);
    re=re*r.re-im*r.im;
    im=temp*r.im+im*r.re;
    return *this;
}

Complexe& Complexe::operator /=(Complexe const &r){
    double temp(re);
    re=(re*r.re+im*r.im)/(r.re*r.re+r.im*r.im);
    im=(r.re*im-temp*r.re)/(r.re*r.re+r.im*r.im);
    return *this;
}

Complexe operator+(Complexe const &r1, Complexe const &r2){
    Complexe r(r1);
    r+=r2;
    return r;
}

Complexe operator-(Complexe const &r1, Complexe const &r2){
    Complexe r(r1);
    r-=r2;
    return r;
}

Complexe operator*(Complexe const &r1, Complexe const &r2){
    Complexe r(r1);
    r*=r2;
    return r;
}

Complexe operator/(Complexe const &r1, Complexe const &r2){
    Complexe r(r1);
    r/=r2;
    return r;
}

Complexe& Complexe::operator =(Complexe const &c){
    im=c.im;
    re=c.re;
    return *this;
 }
