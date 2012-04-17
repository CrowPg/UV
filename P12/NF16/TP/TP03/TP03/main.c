//
//  main.c
//  TP03
//
//  Created by Johan Medioni on 12/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "header.h"

/*typedef struct Art
{
    int id;                          // identificateur unique díun article > 0
    char  libelle [50];       	  // libellÈ de l'article (son nom)
    float PU;                  	  // prix unitaire > 0
    int qte;                   	   // quantitÈ de líarticle prÈsente dans le stock > = 0
    char  categorie [50];  			// catÈgorie de l'article (alimentaire, hygiène, textile, papeterie, etc.)
    struct Art * nextArticle;
}Article;*/

int main (int argc, const char * argv[])
{
    
    Article *a0, *a1, *a2, *a3;
    a0=(Article*)malloc(sizeof(Article));
    a1=(Article*)malloc(sizeof(Article));
    a2=(Article*)malloc(sizeof(Article));
    a3=(Article*)malloc(sizeof(Article));
    a0->id=180;
    a1->id=1;
    a2->id=2;
    a3->id=3;
    a0->nextArticle=a1;
    a1->nextArticle=a2;
    a2->nextArticle=a3;
    a3->nextArticle=a0;
    
    printf("a1 : %d, a2 : %d, a3 : %d ", a1->id, a2->id, a3->id);
    ListeArticles l=a0;
    
    SupprimeStock(l);
    printf("\n\n a1 : %d, a2 : %d, a3 : %d ", l->nextArticle->id, l->nextArticle->nextArticle->id, a3->id);
    return 0;
}

