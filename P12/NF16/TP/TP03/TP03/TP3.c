//
//  TP3.c
//  TP03
//
//  Created by Johan Medioni on 12/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include "header.h"


void SupprimeStock(ListeArticles l)
{
    ListeArticles temp;
    temp=l->nextArticle;
    do
    {
        l->nextArticle=temp->nextArticle;
        free(temp);
        temp=l->nextArticle;
    } while (temp->nextArticle != l);
}