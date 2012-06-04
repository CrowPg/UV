#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define ERROR -1
#define MAX_STR 50
#define MAX_SIZE_PILE 20


typedef struct employe{
    int num;
    char nom[MAX_STR];
    char fct[MAX_STR];
    int age;
    int salaire;
}Employe;

typedef Employe * pEmploye;

typedef struct pile{
    pEmploye tabEmploye[MAX_SIZE_PILE];
    int iSommet;
}Pile;

typedef Pile * pPile;


//fonctions deja developpees
pPile creerPile(void);       //creer une pile vide et retourner son adresse
int	pileVide ( pPile p);    // tester si une pile est vide ou non
int	pilePleine( pPile p);   // tester si une pile est pleine ou non
void empiler( pPile p, pEmploye pE ); //empiler sur une pile
pEmploye depiler( pPile p );        // depiler sur une pile
pEmploye SommetEmploye( pPile p );  //retourner l'adresse de l'employe qui se trouve au sommet d'une pile
void supprimerPile(pPile p);    // liberer tous les memoires louees pour cette pile

void supprimerEmployePile(pPile p, int num); // supprimer un employe dans une pile dont le num est passe en parametre.
pEmploye chercherEmployePile(pPile p, int num); //chercher un employe dans une pile dont le num est passe en parametre.

//fonctions a ajouter si necessaire

#endif // PILE_H_INCLUDED
