//
//  main.c
//  TD_NF16_Martine_et_le_C
//
//  Created by Johan Medioni on 29/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"
#include "exo2.h"
#include "exo3.h"
#include "exo4.h"
#include "exo5.h"


int main (int argc, const char * argv[])
{
    int i;
    int tab[3]={0};
    int tab2[3]={1};
    int tab3[3]={1,3};
    printf("tab tab2 tab3\n");
    for (i=0 ; i<3 ; i++)
    {
        printf("%d \t %d \t  %d\n", tab[i], tab2[i], tab3[i]);
    }
    printf("\n\n\tmiaou");
	return 0;
}

