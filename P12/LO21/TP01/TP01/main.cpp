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

int exercice_1()
{
    int r;
    double p,s;
    cout << "Donnez le rayon entier du cercle";
    cin >> r;
    const double pi=3.14159;
    p=2*pi*r;
    s=pi*r*r;
    cout << "Le cercle de rayon " << r;
    cout << " a un périmètre de " << p << " et une aire de " << s << ".";
    return 0;
}

int main (int argc, const char * argv[])
{
    cout << exercice_1();
    return 0;
}

