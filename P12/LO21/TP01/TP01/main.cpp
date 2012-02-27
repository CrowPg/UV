//
//  main.cpp
//  TP01
//
//  Created by Johan on 27/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include "header.h"

using namespace std ;

int g()
{
    return 2;
}

void exercice_1()
{
    int r;
    double p,s;
    cout << "Donnez le rayon entier du cercle";
    cin >> r;
    p=2*pi*r;
    s=pi*r*r;
    cout << "Le cercle de rayon " << r;
    cout << " a un périmètre de " << p << " et une aire de " << s << ".";
}

void exercice_2()
{
    int x1=10, x2=15, y1;
    y1=f(x1);
    cout << "Valeur de f(x1)=" << y1;
    cout << "Valeur de f(x2)=" << f(x2);
;}

int f(int x)
{
    return x*x-3;
}

Duree exercice_3()
{
    Duree d;
    Duree tab[MAX]={{1,30},{1,0},{2,30},{1,0},{1,15},{90,7},{0,0},{0,0},{0,0},{0,0}}; //initialisation du tableau pour tester
    
    d=sum(tab, 5);
    return d;
}

Duree sum(Duree *x, int n)
{   
    int i;
    unsigned int somme_h=0, somme_m=0;
    Duree d;
    for(i=0; i<n; i++, x++)
    {
        somme_h+=x->h;
        somme_m+=x->m;
    }
    somme_h+=somme_m/60;
    somme_m%=60;
    d.h=somme_h;
    d.m=somme_m;
    return d;
    
}

int main (int argc, const char * argv[])
{
    exercice_3();
    return 0;
}

