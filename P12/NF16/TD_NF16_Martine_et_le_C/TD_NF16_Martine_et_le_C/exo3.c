//
//  exo3.c
//  TD_NF16_Martine_et_le_C
//
//  Created by Johan Medioni on 29/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "exo3.h"

void exercice3_1(void)
{
    int i; // entier
    int* j=0; // pointeur sur un entier
    
    i=5;
    j=&i; // affecte l'adresse de i au pointeur j
    printf("i=%d\n", i);
    printf("contenu pointé par j = %d", *j); // affiche la valeur pointée par j
    printf("adresse pointée par j = %x", j);
}

void exercice3_2(void)
{
    int i; // entier
    int* j=0; // pointeur sur un entier
    
    i=5;
    j=&i; // affecte l'adresse de i au pointeur j
    printf("i=%d\n", i);
    printf("contenu pointé par j = %d", *j); // affiche la valeur pointée par j
    printf("adresse pointée par j = %x", j);
    
    (*j)++; // le contenu pointée par j 
    i*=5; // i=i*5;
    j++; //incrémente l'adresse : attention, si tu fais printf("%d", *j), tu sais pas sur quoi tu vas tomber ... Et tu peux sortir de l'espace mémoire alloué pour le programme et planter. OOPS
}