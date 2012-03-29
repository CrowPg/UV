//
//  Exercice_2.c
//  TD04
//
//  Created by Johan Medioni on 28/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>

struct monome
{
    int coeff;
    int degre;
    struct monome *suiv;
};

typedef struct monome *polynome;

polynome polynomeconstructor(int c, int d, polynome P);


polynome polynomeconstructor(int c, int d, polynome P)
{
    struct monome *m;
    m->coeff = c;
    m->degre = d;
    m->suiv = P;
    return m;
}

int degre(polynome P);

int degre(polynome P)
{
    struct monome *it=P;
    int d=-1;
    while(it !=NULL)
    {
        if (d<it->degre)
        {
            d=it->degre;
        }
        it=it->suiv;
    }
    return d;
}

