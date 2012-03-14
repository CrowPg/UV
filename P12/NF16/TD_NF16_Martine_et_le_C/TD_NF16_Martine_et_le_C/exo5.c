//
//  exo5.c
//  TD_NF16_Martine_et_le_C
//
//  Created by Johan Medioni on 14/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "exo5.h"

int somme_5(void)
{
    int a, b, c, d, e, f, g, h, i, j, res;
    printf("Entres les 10 valeurs\n");
    scanf("%d %d %d %d %d %d %d %d %d %d ", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
    printf("\nLes valeurs entrées sont : %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j);
    res=a+b+c+d+e+f+g+h+i+j;
    printf("Le résultat est : %d", res);
    return res;
}

float calcul_dec(void)
{
    float a, b, c;
    a=(float)5/2;
    b=5/2;
    c=5.0/2; /*Attention aux divisions ! */
    printf("%f\n%f\n%f", a, b, c);
    return a;
}

float moy_5(void)
{
    float m;
    m=(float)somme_5()/10;
    printf("%f", m);
    return m;
}

float prod_5(void)
{
    int a, b, c, d, e, f, g, h, i, j;
    float prod; // On va faire un produit, mieux vaut utiliser float pour éviter les débordements !!!
    printf("Entres les 10 valeurs\n");
    scanf("%d %d %d %d %d %d %d %d %d %d ", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
    printf("\nLes valeurs entrées sont : %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j);
    prod=a+b+c+d+e+f+g+h+i+j;
    printf("Le résultat est : %f", prod);
    return prod;

}

int diff_a_A(void)
{
    int diff;
    diff=abs('A'-'a');
    printf("%d", diff);
    return diff;
}

void MAJ(void)
{
    char c;
    printf("Entrez le caractère :");
    scanf("%c", &c);
    if (c>='a' && c<='z')
    {
        c=c-diff_a_A();
        printf("\n%c", c); 
    }
}
