//
//  exo2.c
//  TD_NF16_Martine_et_le_C
//
//  Created by Johan Medioni on 29/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "exo2.h"

void Bonjour(void)
{
    printf("Bonjour, je ne sers à rien.");
}

void Bonjour_ligne(void)
{
    printf("\n\nBonjour, je ne sers à rien. \n\n");
}

void Bonjour_caractere(void)
{
    char carac;
    printf("\n\nBonjour, je ne sers à rien. \n\nEntre un caractère.");
    scanf("%c", &carac);
    printf("\n\nsigne : %c, ASCII decimal : %d, ASCII hexadecimal : %x \n", carac, carac, carac);
}