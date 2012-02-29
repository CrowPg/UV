//
//  exo4.c
//  TD_NF16_Martine_et_le_C
//
//  Created by Johan Medioni on 29/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "exo4.h"

void nombre_test(int a)
{
    if ((a >= 7 && a <= 20) || a==127)
        printf("OK");
    else
        printf("non");
}

void alaphabet_test(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        printf("OK");
    else
        printf("non");
}