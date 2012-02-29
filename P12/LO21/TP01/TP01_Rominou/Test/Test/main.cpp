//
//  main.cpp
//  Test
//
//  Created by Romain Butteaud on 26/02/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

void exo1(){
    const double pi = 3.14159;
    int r;
    double p, s;
    cout << "Donnez le rayon entier d'un cercle : ";
    cin >> r;
    p = 2*pi*r;
    s = pi*r*r;
    cout << "Le cercle a un rayon de : " << r;
    cout << " et un perimetre de " << p << " et une surface de " << s; 
}

int f(int x) {
    return x*x-3;
}

void exo2() {
    int x1= 10, x2=15, y1;
    y1=f(x1);
    cout << "Valeur de f(x1) : " << y1 << "\n";
    cout << "Valeur de f(x2) : " << f(x2) << "\n";
}

Duree sum(Duree* x, int n){
    int i;
    unsigned int somme_h=0, somme_m=0;
    Duree d;
    for(i=0; i<n; i++) {
        somme_h+=x[i].h;
        somme_m+=x[i].m;
    }
    somme_h+=somme_m/60;
    somme_m%=60;
    d.h=somme_h;
    d.m=somme_m;
    return d;
}

void exo3(){
    Duree d;
    Duree tab[MAX];
    d=sum(tab,5);
}


void raz (Personne *p) {
    *p->nom = NULL;
    p->age = 0;
}

void affiche_struct (const Personne *p) {
    cout<< "Nom : "<< p->nom << "\n";
    cout<< "Age : "<< p->age << "\n";
}


int main (int argc, const char * argv[]) {
    Personne p = {"Romain", 21};
    affiche_struct(&p);
    return 0;
}
