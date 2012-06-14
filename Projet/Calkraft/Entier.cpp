#include "Entier.h"

Entier& Entier::operator+=(Entier const &n){
    val+=n.val;
    return *this;
}

Entier& Entier::operator-(){
    val=-val;
    return *this;
}

Entier& Entier::operator-=(Entier const &n){
    val-=n.val;
    return *this;
}

Entier& Entier::operator*=(Entier const &n){
    val*=n.val;
    return *this;
}

Entier& Entier::operator/=(Entier const &n){
    val/=n.val;
    return *this;
}

Entier operator +(Entier const &n1, Entier const &n2){
    Entier n(n1);
    n+=n2;
    return n;
}

Entier operator -(Entier const &n1, Entier const &n2){
    Entier n(n1);
    n-=n2;
    return n;
}

Entier operator *(Entier const &n1, Entier const &n2){
    Entier n(n1);
    n*=n2;
    return n;
}

Entier operator /(Entier const &n1, Entier const &n2){
    Entier n(n1);
    n/=n2;
    return n;
}

Entier& Entier::operator =(Entier const &n){
    val=n.val;
    return *this;
}
