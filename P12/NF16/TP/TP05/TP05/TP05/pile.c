#include "pile.h"

//fonctions deja developpees
pPile creerPile(void) {
    pPile p = (pPile)malloc(sizeof(Pile));

    if(p==NULL)
    {
        perror("erreur: pile.c : fonction creerPile: manque de memoire");
        return NULL;
    }

	p->iSommet = -1;

	return p;
}

int	pileVide ( pPile p) {
    if(p == NULL)
    {
        perror("erreur: pile.c : fonction pileVide: pointeur NULL");
        return ERROR;
    }

	if (p->iSommet == -1)
		return 1;
	else
		return 0;
}

int	pilePleine( pPile p) {
    if(p == NULL)
    {
        perror("erreur: pile.c : fonction pilePleine: pointeur NULL");
        return ERROR;
    }

	if (p->iSommet == (MAX_SIZE_PILE -1) )
		return 1;
	else
		return 0;
}

void empiler( pPile p, pEmploye pE ) {
    if(p == NULL || pE == NULL)
    {
        perror("erreur: pile.c : fonction empiler: pointeur NULL");
        return;
    }

	if (pilePleine(p)) {
		printf("erreur: pile.c : fonction empiler: la Pile est pleine\n");
		return;
	}

	p->iSommet = p->iSommet + 1;
	p->tabEmploye[ p->iSommet] = pE;
}

pEmploye depiler( pPile p ) {
	pEmploye pE;
    if(p == NULL)
    {
        perror("erreur: pile.c : fonction depiler: pointeur NULL");
        return NULL;
    }

	if (pileVide(p)) {
		printf("erreur: pile.c : fonction depiler: la Pile est vide\n");
		return NULL;
	}

	pE = p->tabEmploye[ p->iSommet ];
	p->iSommet = p->iSommet-1;
	return pE;
}

pEmploye SommetEmploye( pPile p )
{
    if(p == NULL)
    {
        perror("erreur: pile.c : fonction SommetEmploye: pointeur NULL");
        return NULL;
    }

	if (pileVide(p)) {
		printf("erreur: pile.c : fonction SommetEmploye: la Pile est vide\n");
		return NULL;
	}

	return p->tabEmploye[ p->iSommet ];
}


void supprimerPile(pPile p)
{
    pEmploye pE;

    if(p == NULL)
    {
        perror("erreur: pile.c : fonction supprimerPile: pointeur NULL");
        return;
    }

    while(!pileVide(p))
    {
      pE = depiler(p);
      free(pE);
    }

	free(p);
}


void supprimerEmployePile(pPile p, int num)
{
    pPile p2 = creerPile();
    pEmploye pE=NULL;
    pEmploye pE2=NULL;


    if(p == NULL)
    {
        perror("erreur: pile.c : fonction supprimerEmployePile: pointeur NULL");
        return;
    }

	if (pileVide(p)) {
		printf("erreur: pile.c : fonction supprimerEmployePile: la Pile est vide\n");
		return;
	}

    while(!pileVide(p))
    {
        pE2 = depiler(p);
        if((pE2->num) == num)
        {
            pE = pE2;
            break;
        }
        else
            empiler(p2,pE2);
    }

    while(!pileVide(p2))
    {
        pE2 = depiler(p2);
        empiler(p,pE2);
    }

    supprimerPile(p2);
    free(pE);
}

pEmploye chercherEmployePile(pPile p, int num)
{
    pPile p2 = creerPile();
    pEmploye pE=NULL;
    pEmploye pE2=NULL;


    if(p == NULL)
    {
        perror("erreur: pile.c : fonction chercherEmployePile: pointeur NULL");
        return NULL;
    }

	if (pileVide(p)) {
		printf("erreur: pile.c : fonction chercherEmployePile: la Pile est vide\n");
		return NULL;
	}

    while(!pileVide(p))
    {
        pE2 = SommetEmploye(p);
        if((pE2->num) == num)
        {
            pE = pE2;
            break;
        }
        else
        {
            depiler(p);
            empiler(p2,pE2);
        }
    }

    while(!pileVide(p2))
    {
        pE2 = depiler(p2);
        empiler(p,pE2);
    }

    supprimerPile(p2);
    return pE;
}

//fonctions a ajouter si necessaire
