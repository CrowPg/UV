//
//  exo1.c
//  TD_NF16_Martine_et_le_C
//
//  Created by Johan Medioni on 29/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "exo1.h"
#include <stdio.h>

#define PI 3.14159

void aire_cercle(void)
{
    int rayon=10;
    double resultat;
    resultat=PI*rayon*rayon;
    printf("The result is : %f", resultat);
}

void aff_in(void)
{
    int x, y, temp;
    printf("Donnez x puis y.");
    scanf("%d", &x);
    scanf("%d", &y);
    temp=x;
    x=y;
    y=temp;
    printf("x=%d, y=%d", x, y );
}

void dec(void)
{
    char c;
    c='7';
    printf("%c", c);
    c=98 ;
    printf("%c", c);
}