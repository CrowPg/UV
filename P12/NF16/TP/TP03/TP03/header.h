#ifndef TP3_H
#define TP3_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// dÈfinition des structures

typedef struct Art
{
    int id;                          // identificateur unique díun article > 0
    char  libelle [50];       	  // libellÈ de l'article (son nom)
    float PU;                  	  // prix unitaire > 0
    int qte;                   	   // quantitÈ de líarticle prÈsente dans le stock > = 0
    char  categorie [50];  			// catÈgorie de l'article (alimentaire, hygiËne, textile, papeterie, etc.)
    struct Art * nextArticle;
}Article;

typedef Article * ListeArticles;

typedef struct Req
{
    int idArticle;          // identificateur de líarticle
    int qte;                  // quantitÈ ‡ retirer ou ‡ ajouter dans le stock correspondant ‡ idArticle
    struct Req * nextRequete;
}Requete ;

typedef Requete * ListeRequetes;

// dÈclaration des variables globales utilisÈes

ListeArticles Liste_stock_dispo ;
ListeArticles Liste_stock_epuise ;



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
