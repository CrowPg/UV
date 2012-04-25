#ifndef TP3_H
#define TP3_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// définition des structures

typedef struct Art
{
    int id;                          // identificateur unique d’un article > 0
    char  libelle [50];       	  // libellé de l'article (son nom)
    float PU;                  	  // prix unitaire > 0
    int qte;                   	   // quantité de l’article présente dans le stock > = 0
    char  categorie [50];  			// catégorie de l'article (alimentaire, hygiène, textile, papeterie, etc.)
    struct Art * nextArticle;
}Article;

typedef Article * ListeArticles;

typedef struct Req
{
    int idArticle;          // identificateur de l’article
    int qte;                  // quantité à retirer ou à ajouter dans le stock correspondant à idArticle
    struct Req * nextRequete;
}Requete ;

typedef Requete * ListeRequetes;

// dŽclaration des variables globales utilisées

ListeArticles Liste_stock_dispo ;
ListeArticles Liste_stock_epuise ;

//Fonction utiles
Article* CreerArticle(int id, char libelle[], float PU, int qte, char categorie[]);
ListeArticles CreerListe();
void AfficherArticle(Article* a);
Requete* CreerRequete(int id, int qtte);


// prototypes de fonctions
ListeArticles CreeListeArticles();
ListeRequetes CreeListeRequetes();
void AjoutArticle(ListeArticles liste, Article *a);
void AjoutRequete(ListeRequetes liste, Requete *req);
void AfficheStock(ListeArticles liste) ;
void SupprimeStock(ListeArticles l) ;
void SupprimeRequetes(ListeRequetes liste) ;
void SupprimeArticle(ListeArticles l, int id_Article) ;
ListeArticles RechercheArticleParCritere(ListeArticles liste, int id, char* libelle, char* categorie) ;
ListeArticles RechercheParQuantite(ListeArticles liste, int qte_min, int qte_max) ;
ListeArticles RechercheParPrixUnitaire (ListeArticles liste, float prix_min , float prix_max) ;

void MiseAJourArticle(int id, int quantite) ;
void VendreArticles(ListeRequetes liste) ;
void ApprovisionnerMagasin(ListeRequetes liste) ;
void LireFichier(char* nomfichier);



#endif
