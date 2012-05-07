#include <stdio.h>
#include <stdlib.h>
#include "TP3.h"

int main()
{
    printf("Et c'est parti.");
    Article* L=CreeListeArticles();
    Article* a1=CreeListeArticles(1, "Miaou", 3, 30, "Chat");
    AjoutArticle(L, a1);
    AfficheStock(L);
    SupprimeStock(L);
    return 0;
}

