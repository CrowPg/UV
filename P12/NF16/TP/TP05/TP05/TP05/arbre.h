#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include "pile.h"


typedef struct noeud{
    pPile pileEmploye;
    int salaire;
    struct noeud * pere;
    struct noeud * gch;
    struct noeud * drt;
} Noeud;

typedef Noeud * pNoeud;

typedef struct pileN{
    pNoeud tabNoeud[MAX_SIZE_PILE];
    int iSommet;
} PileN;

typedef PileN * pPileN;


//fonctions deja developpees
pPileN creerPileN(void); //creer une pile vide et retourner son adresse
int	pileVideN ( pPileN p);// tester si une pile est vide ou non
int	pilePleineN( pPileN p ); // tester si une pile est pleine ou non
void empilerN( pPileN p, pNoeud pN );//empiler sur une pile
pNoeud depilerN( pPileN p); // depiler sur une pile
pNoeud SommetNoeud( pPileN p ); //retourner l'adresse du noeud qui se trouve au sommet d'une pile
void supprimerPileN(pPileN p);// liberer tous les memoires louees pour cette pile

pNoeud minimumABR(pNoeud arbre);  //chercher et retourner l'adresse du noeud ayant la plus petite valeur dans un arbre
pNoeud succeseurABR(pNoeud noeud);       //chercher et retourner l'adresse du successeur d'un noeud donnee.Retourner NULL si il n'a pas de succeseur
void copyEmployer(pEmploye pe1, pEmploye pe2); //copier le contenu de pe2 dans pe1

//fonctions a developper. libre a vous de rajouter des autres fonctions si necessaire
pNoeud nouveauNoeud(int salaire);
pEmploye nouveauEmploye(int num, char * nom, char * fonction,  int age, int salaire);
pNoeud chercherEmploye(pNoeud arbre, int numero);
pNoeud insererEmploye(pNoeud arbre, pEmploye employe);
pNoeud supprimerNoeud(pNoeud arbre, pNoeud noeud);
pNoeud supprimerEmploye(pNoeud arbre, int numero);
pNoeud modifierEmploye(pNoeud arbre, int numero, char * nom, char * fonction, int age, int salaire) ;
void afficherEmployes(pNoeud arbre);
void supprimerArbre(pNoeud arbre);
pNoeud lireFichier(pNoeud arbre, char * f);
void ecrireFichier(pNoeud arbre, char * f);

#endif // ARBRE_H_INCLUDED
