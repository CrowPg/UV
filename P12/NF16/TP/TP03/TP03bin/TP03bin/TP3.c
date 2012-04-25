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

Requete* CreerRequete(int id, int qtte)
{
    Requete *r;
    r=(Requete*)malloc(sizeof(Requete));
    r->idArticle=id;
    r->qte=qtte;
    return r;
}

ListeArticles CreerListe(){
	ListeArticles sent=(ListeArticles)malloc(sizeof(Article));
	sent->nextArticle=sent;
	return sent;
}

void AfficherArticle(Article* a){
		printf("\n| %d \t| %s \t | \t %f | \t %d \t | %s \t |\n",a->id,a->libelle,a->PU,a->qte,a->categorie);
}

void AjoutArticle(ListeArticles liste, Article *a){
	ListeArticles temp=liste;
	if (temp->nextArticle!=liste){				//si la liste n'est pas vide 
		while(temp->nextArticle!=liste && temp->nextArticle->PU > a->PU)		//Tant que l'article a un prix inférieur
		{
			temp=temp->nextArticle;
		}
		a->nextArticle=temp->nextArticle;
		temp->nextArticle=a;	
	}
	else{						//Sinon la liste est vide e
		liste->nextArticle=a;		
		a->nextArticle=liste;
	}
}

void AjoutRequete(ListeRequetes liste, Requete *req)
{
    ListeRequetes temp=liste;
    if (temp->nextRequete!=liste) // si la liste n'est pas vide
    {
        while(temp->nextRequete->nextRequete!=liste)
        {
            temp=temp->nextRequete; // on parcourt la liste
        }
        req->nextRequete=temp->nextRequete; // on fait pointer le suiv de req sur ce qui doit maintenant tre la sentinelle (Žtape 1 de l'insertion)
        temp->nextRequete=req; // on fait pointer le suiv de temp sur req pour complŽter l'insertion
    }
    else // si la liste est vide
    {
        liste->nextRequete=req;
        req->nextRequete=liste;
         
    }
}

void AfficheStock(ListeArticles l){
	ListeArticles temp=l;
	printf("\n-------------------------------------------------------------------------------------\n| Identifiant\t | Libelle\t| Prix Unitaire\t | Quantite\t | Categorie\t |\n-------------------------------------------------------------------------------------\n");
	if(temp->nextArticle==l) printf("La liste est vide\n");
	else while(temp->nextArticle!=l){
		temp=temp->nextArticle;
		AfficherArticle(temp);
	}
}

void SupprimeArticle(ListeArticles l, int id_article)
{
        ListeArticles temp=l;
        while(temp->nextArticle!=l)
        {
            if(temp->nextArticle->id==id_article)
            {
                ListeArticles aEffacer = temp->nextArticle;
                temp->nextArticle=temp->nextArticle->nextArticle;
                free(aEffacer);
                break;
                
            }
            temp=temp->nextArticle;
        }


}

void SupprimeStock(ListeArticles l){
	ListeArticles temp;
	while (l->nextArticle != l)
    {
		temp=l->nextArticle;
		l->nextArticle=temp->nextArticle;
        free(temp);
    } 
}

/*void VendreArticles(ListeRequetes r)
{
    while (r->nextRequete!=r)
    {
        if(r->qte<0)
        {
            ListeRequetes aExe=r;
            MiseAJourArticle(r->idArticle, r->qte);
            r=r->nextRequete;
            free(aExe);
        }
        else r=r->nextRequete;
    }
}

void ApprovisionnerMagasin (ListeRequetes r)
{
    while (r->nextRequete!=r)
    {
        if(r->qte>0)
        {
            ListeRequetes aExe=r;
            MiseAJourArticle(r->idArticle, r->qte);
            r=r->nextRequete;
            free(aExe);
        }
        else r=r->nextRequete;
    }
}*/



/*
ListeArticles RechercheArticleParCritere(ListeArticles liste, int id, char* libelle, char* categorie){
	ListeArticles resultat=CreerListe();
	ListeArticles temp=liste->nextArticle;

	//Cas Liste vide
	if(liste->nextArticle==liste) {
		printf("\nListe vide\n");
		return resultat;
	}

	//Sinon
	while(temp!=liste){
		if(id!=-1){
			if(temp->id==id)
				if(libelle=="IGNORE")
					if(categorie=="IGNORE"){
						AjoutArticle(resultat,temp);




}
*/