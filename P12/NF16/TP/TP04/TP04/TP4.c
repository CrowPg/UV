#include "TP3.h"

Article* CreerArticle(int id, char libelle[], float PU, int qte, char categorie[]){

	Article * a;

	a=(Article*)malloc(sizeof(Article));

	a->id=id;

	strcpy(a->libelle,libelle);

	a->PU=PU;

	a->qte=qte;

	strcpy(a->categorie,categorie);

	a->nextArticle=NULL;

	return a;

}
