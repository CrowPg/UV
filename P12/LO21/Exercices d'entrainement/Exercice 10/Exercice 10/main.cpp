//
//  main.cpp
//  Exercice 10
//
//  Created by Johan Medioni on 18/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "header.h"
using namespace std;

Date Date::ModifDateVal(Date d, unsigned int j, unsigned int m, unsigned int a)
{
    d.jour=j;
    d.mois=m;
    d.annee=a;
    return d;
}

void Date::ModifDateAdr(Date *d, unsigned int j, unsigned int m, unsigned int a)
{
    d->jour=j;
    d->mois=m;
    d->annee=a;
}

void Date::ModifDateRef(Date &d, unsigned int j, unsigned int m, unsigned int a)
{
    d.jour=j;
    d.mois=m;
    d.annee=a;
}
int main (int argc, const char * argv[])
{
    
    return 0;
}

