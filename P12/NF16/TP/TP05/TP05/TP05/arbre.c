#include "arbre.h"

//fonctions deja developpees
pPileN creerPileN(void) {
    pPileN p = (pPileN)malloc(sizeof(PileN));

    if(p==NULL)
    {
        perror("erreur: pile.c : fonction creerPileN: manque de memoire");
        return NULL;
    }

	p->iSommet = -1;

	return p;
}

int	pileVideN ( pPileN p) {
    if(p == NULL)
    {
        perror("erreur: pile.c : fonction pileVideN: pointeur NULL");
        return ERROR;
    }

	if (p->iSommet == -1)
		return 1;
	else
		return 0;
}

int	pilePleineN( pPileN p) {
    if(p == NULL)
    {
        perror("erreur: pile.c : fonction pilePleineN: pointeur NULL");
        return ERROR;
    }

	if (p->iSommet == (MAX_SIZE_PILE -1) )
		return 1;
	else
		return 0;
}

void empilerN( pPileN p, pNoeud pN) {
    if(p == NULL || pN == NULL)
    {
        perror("erreur: pile.c : fonction empilerN: pointeur NULL");
        return;
    }

	if (pilePleineN(p)) {
		printf("erreur: pile.c : fonction empilerN: la Pile est pleine\n");
		return;
	}

	p->iSommet = p->iSommet + 1;
	p->tabNoeud[ p->iSommet] = pN;
}

pNoeud depilerN( pPileN p) {
	pNoeud pN;
    if(p == NULL)
    {
        perror("erreur: pile.c : fonction depilerN: pointeur NULL");
        return NULL;
    }

	if (pileVideN(p)) {
		printf("erreur: pile.c : fonction depilerN: la Pile est vide\n");
		return NULL;
	}

	pN = p->tabNoeud[ p->iSommet];
	p->iSommet = p->iSommet-1;
	return pN;
}

pNoeud SommetNoeud( pPileN p )
{
     if(p == NULL)
    {
        perror("erreur: pile.c : fonction SommetNoeud: pointeur NULL");
        return NULL;
    }

	if (pileVideN(p)) {
		printf("erreur: pile.c : fonction SommetNoeud: la Pile est vide\n");
		return NULL;
	}

	return p->tabNoeud[ p->iSommet];
}


void supprimerPileN(pPileN p)
{
    pNoeud pN;

    if(p == NULL)
    {
        perror("erreur: pile.c : fonction supprimerPileN: pointeur NULL");
        return;
    }

    while(!pileVideN(p))
    {
      pN = depilerN(p);
      free(pN);
    }

	free(p);
}


pNoeud minimumABR(pNoeud arbre)
{
    pNoeud pN;
    pN = arbre;

    if(arbre==NULL)
    {
         perror("erreur: arbre.c : fonction minimumABR: pointeur NULL");
         return NULL;
    }

    while(pN->gch!=NULL)
        pN = pN->gch;

    return pN;
}

pNoeud succeseurABR(pNoeud noeud)
{
      pNoeud pNX,pNY;

      if(noeud->drt != NULL)
            return minimumABR(noeud->drt);

      pNY = noeud->pere;
      pNX = noeud;

      while(pNY!=NULL && pNX == pNY->drt)
      {
        pNX = pNY;
        pNY = pNY->pere;
      }
      return pNY;
}

void copyEmployer(pEmploye pe1, pEmploye pe2)
{
    pe1->num = pe2->num;
    strcpy(pe1->nom,pe2->nom);
    strcpy(pe1->fct,pe2->fct);
    pe1->age = pe2->age;
    pe1->salaire = pe2->salaire;
}


//fonctions a developper. libre a vous de rajouter des autres fonctions si necessaire

pNoeud nouveauNoeud(int salaire){
    pNoeud n= (Noeud*) malloc(sizeof(Noeud));
    n->salaire=salaire;
    n->drt=NULL;
    n->gch=NULL;
    n->pere=NULL;
    n->pileEmploye=creerPile();
    return n; //si le malloc échoue, n=NULL, donc la fonction retourne bien NULL en cas d'échec
}

pEmploye nouveauEmploye(int num, char* nom, char* fonction, int age, int salaire){
    pEmploye ne=(Employe*) malloc(sizeof(Employe));
    ne->num=num;
    strcpy(ne->nom, nom);
    strcpy(ne->fct, fonction);
    ne->age=age;
    ne->salaire=salaire;
    return ne;
}

pNoeud insererEmploye(pNoeud arbre, pEmploye employe){
    pNoeud temp=arbre;
    if (temp->salaire==employe->salaire){ //si on est sur le bon noeud
        empiler(temp->pileEmploye, employe);//on empile
        return (arbre);
    }
    else if (temp->salaire>employe->salaire){
        if (temp->gch == NULL){
            temp->gch=nouveauNoeud(employe->salaire);
        }
        insererEmploye(temp->gch, employe);
        
    }//sinon, si le salaire de l'employe est inférieur à celui du noeud courant, on va à gauche (en créant le noeud si nécessaire), et on relance la fonction sur le nouveau noeud
    else {//sinon (si le salaire de l'employe est supérieur à celui du courant), on va à droite (en créant le noeud si nécessaire), et on relance la fonction sur le nouveau noeud
        if (temp->drt == NULL){
            temp->drt=nouveauNoeud(employe->salaire);
        }
        insererEmploye(temp->drt, employe);
    }
    return NULL;//Si on arrive ici, il y a eu un problème, donc on retourne NULL par défaut
}

pNoeud modifierEmploye(pNoeud arbre, int id, char* nom, char* fonction, int age, int salaire){
    pNoeud temp = chercherEmploye(arbre, id);
    if (temp == NULL){
        printf("Cet employé n'existe pas. Retour de l'arbre non modifié.");
        return arbre;
    }
    else{
        pEmploye me=chercherEmployePile(temp->pileEmploye, id);
        me->age=age;
        strcpy(me->nom, nom);
        strcpy(me->fct, fonction);
        if (salaire != me->salaire){
            insererEmploye(arbre, me);
            supprimerEmployePile(temp->pileEmploye, id);
        }
    }
    return arbre;
}
