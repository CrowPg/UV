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

void AfficherArticle(Article* a){
		printf("| \t%d\t| %s\t| %.2f\t| %d\t\t| %s\t|\n",a->id,a->libelle,a->PU,a->qte,a->categorie);
}

void AjoutArticle(ListeArticles liste, Article *a){
	ListeArticles temp=liste;
	if((liste==Liste_stock_dispo || liste==Liste_stock_dispo) && IdPresent(a->id))
		printf("\nERREUR : Ajout de %s impossible car id %d deja present dans l'inventaire!\n",a->libelle,a->id);
	else{
		if (temp->nextArticle != liste){				//si la liste n'est pas vide 
			while(temp->nextArticle != liste && temp->nextArticle->PU > a->PU){		//Tant que l'article à insérer a un prix inférieur
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
}

void AfficheStock(ListeArticles l){
	ListeArticles temp=l;
	if(temp->nextArticle==l) printf("La liste est vide\n");
	else{
		printf("\n-----------------------------------------------------------------------------\n| Identifiant\t| Libelle| PU\t\t| Quantite\t| Categorie\t|\n-----------------------------------------------------------------------------\n");
		while(temp->nextArticle!=l){
			temp=temp->nextArticle;
			AfficherArticle(temp);
		}
	}
}

ListeArticles CreerListe(void){
	ListeArticles sent=(ListeArticles)malloc(sizeof(Article));
	sent->nextArticle=sent;
	return sent;
}

void AjoutNewArticle(Article* liste, Article *a){
	Article* art;
	art=CreerArticle(a->id,a->libelle,a->PU,a->qte,a->categorie);
	AjoutArticle(liste,art);
}

ListeArticles RechercheArticleParCritere(ListeArticles liste, int id, char* libelle, char* categorie){
	ListeArticles resultat=CreerListe();
	Article* temp=liste->nextArticle;

	//Cas Liste vide
	if(liste->nextArticle==liste) {
		printf("\nListe vide, recherche impossible\n");
		return resultat;
	}

	printf("\n***** Resultat de la recherche par critere*****\n\tid: %d | libelle: %s | categorie: %s\n",id, libelle, categorie);

	//Cas Recherche avec id
	if(id!=-1){					//Cas particulier : chaque article a un id unique, la recherche ne va donc retourner qu'un article!
		while(temp!=liste){
			if(temp->id==id){
				AjoutNewArticle(resultat,temp);
				break;
			}
		}
		if(resultat->nextArticle!=resultat){			//Si on a trouvé un article avec l'id correspondant
			AfficheStock(resultat);
			if(strcmp(categorie,IGNORE)!=0)						
				if(resultat->nextArticle->categorie!=categorie)
					printf("NOTE : la Categorie de l'article trouve ne correspond pas !\n");
			if(strcmp(libelle,IGNORE)!=0)
				if(resultat->nextArticle->libelle!=categorie)
					printf("NOTE : le Libelle de l'article trouve ne correspond pas !\n");
		}
		return resultat;
	}

	//Sinon
	while(temp!=liste){
				if(strcmp(libelle,IGNORE)!=0 && strcmp(categorie,IGNORE)!=0){
					if(strcmp(temp->libelle,libelle)==0 && strcmp(temp->categorie,categorie)==0)
						AjoutNewArticle(resultat,temp);
				}
				else if(strcmp(libelle,IGNORE)==0 && strcmp(categorie,IGNORE)!=0){
					if(strcmp(temp->categorie,categorie)==0)
						AjoutNewArticle(resultat,temp);
				}
				else if(strcmp(libelle,IGNORE)!=0 && strcmp(categorie,IGNORE)==0){
					if(strcmp(temp->libelle,libelle)==0)
						AjoutNewArticle(resultat,temp);
				}
				else if(strcmp(libelle,IGNORE)==0 && strcmp(categorie,IGNORE)==0)
						AjoutNewArticle(resultat,temp);				
		}
	if(resultat->nextArticle!=resultat)
		AfficheStock(resultat);
	else printf("\n\t Aucun article trouve\n");
	return resultat;
}

ListeArticles RechercheParQuantite(ListeArticles liste, int qte_min, int qte_max){
	ListeArticles resultat=CreerListe();
	Article* temp=liste->nextArticle;

	if(qte_min>qte_max || qte_min<0){
		printf("\n Erreur : Bornes incorrectes\n");
		return resultat;
	}

	//Cas Liste vide
	if(liste->nextArticle==liste) {
		printf("\nListe vide, recherche impossible\n");
		return resultat;
	}

	printf("\n***** Resultat de la recherche par quantite*****\n\tmin: %d | max: %d\n",qte_min, qte_max);
	while(temp!=liste){
		if(temp->qte <= qte_max && temp->qte >= qte_min)
			AjoutNewArticle(resultat,temp);				
		}
	if(resultat->nextArticle!=resultat)
		AfficheStock(resultat);
	else printf("\n\t Aucun article trouve\n");
	return resultat;
}

ListeArticles RechercheParPrixUnitaire (ListeArticles liste, float prix_min , float prix_max){
	ListeArticles resultat=CreerListe();
	Article* temp=liste->nextArticle;

	if(prix_min>prix_max || prix_min<0){
		printf("\n Erreur : Bornes incorrectes\n");
		return resultat;
	}

	//Cas Liste vide
	if(liste->nextArticle==liste) {
		printf("\nListe vide, recherche impossible\n");
		return resultat;
	}

	printf("\n***** Resultat de la recherche par prix unitaire*****\n\tmin: %f | max: %f\n",prix_min, prix_max);
	while(temp!=liste){
		if(temp->PU<=prix_max && temp->PU>=prix_min)
			AjoutNewArticle(resultat,temp);				
		}
	if(resultat->nextArticle!=resultat)
		AfficheStock(resultat);
	else printf("\n\t Aucun article trouve\n");
	return resultat;
}

void LibererListe(ListeArticles liste){
	SupprimeStock(liste);
	free(liste);
}

void MiseAJourArticle(int id, int quantite){
	ListeArticles resultat = RechercheArticleParCritere(Liste_stock_dispo,id,IGNORE,IGNORE);
	if(resultat->nextArticle != resultat){
			resultat->nextArticle->qte += quantite;
			if(quantite < 0) printf("\nERREUR : Il ne reste pas assez d'elements en stock pour effectuer la vente.\n");
			else{
				SupprimeArticle(Liste_stock_dispo,id);
				if(quantite==0)
					AjoutArticle(Liste_stock_epuise,resultat->nextArticle);
				else
					AjoutArticle(Liste_stock_dispo,resultat->nextArticle);
			}
	}
	else {
		resultat = RechercheArticleParCritere(Liste_stock_epuise,id,IGNORE,IGNORE);
		if(resultat->nextArticle != resultat){
			if(quantite > 0){
				resultat->nextArticle->qte+=quantite;
				SupprimeArticle(Liste_stock_epuise,id);
				AjoutArticle(Liste_stock_dispo,resultat->nextArticle);
			}
			else
				printf("\n ERREUR : Impossible de vendre, stock deja epuise...\n");
		}
		else
			printf("\nERREUR : Mise a jour impossible\n");
	}
	LibererListe(resultat);
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

void SupprimeArticle(ListeArticles l, int id_article)
{
        ListeArticles temp=l;
		ListeArticles ArticleAEffacer;
        while(temp->nextArticle!=l)
        {
            if(temp->nextArticle->id==id_article)
            {
				ArticleAEffacer=temp->nextArticle;
                temp->nextArticle=temp->nextArticle->nextArticle;
				free(ArticleAEffacer);
                break;
            }
            temp=temp->nextArticle;
        }
}

void VendreArticles(ListeRequetes r)
{
    while (r->nextRequete!=r){
        if(r->qte<0){
            ListeRequetes aExe=r;
            MiseAJourArticle(r->idArticle, r->qte);
            r=r->nextRequete;
            free(aExe);
        }
        else
			r=r->nextRequete;
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
        else
			r=r->nextRequete;
    }
}

void AjoutRequete(ListeRequetes liste, Requete *req){
	ListeRequetes temp=liste;
	if (temp->nextRequete!=liste){ // si la liste n'est pas vide
		while(temp->nextRequete->nextRequete!=liste){
			temp=temp->nextRequete; // on parcourt la liste
		}
		req->nextRequete=temp->nextRequete; // on fait pointer le suiv de req sur ce qui doit maintenant être la sentinelle (étape 1 de l'insertion)
		temp->nextRequete=req; // on fait pointer le suiv de temp sur req pour compléter l'insertion
	}
	else{ // si la liste est vide
	liste->nextRequete=req;
	req->nextRequete=liste;
	}
}

Requete* CreerRequete(int id, int qtte){
	Requete *r;
	r=(Requete*)malloc(sizeof(Requete));
	r->idArticle=id;
	r->qte=qtte;
	return r;
}

void LireFichier(char* nomfichier){
	FILE* f=NULL;
	Article* newArticle;
	int id,qte;
	float PU;
	char libelle[50];
	char categorie[50];
	char T1[50];
	char T2[50];
	char T3[50];
	char T4[50];
	char T5[50];

	f=fopen(nomfichier, "r");		//	Ouverture du fichier

	if(f==NULL){
		printf("\nERREUR : Impossible d'ouvrir le fichier %s",nomfichier);
	}
	else{
		while(!feof(f)){
			if(ftell(f)==SEEK_SET){
				fscanf(f,"%s\t%s\t%s\t%s\t%s",T1,T2,T3,T4,T5);
				printf("\n%s\t%s\t%s\t%s\t%s\n",T1,T2,T3,T4,T5);
			}
			fscanf(f,"\n%d\t%s\t%f\t%d\t%s",&id,libelle,&PU,&qte,categorie);
			printf("\n%d\t%s\t%f\t%d\t%s",id,libelle,PU,qte,categorie);
			newArticle=CreerArticle(id,libelle,PU,qte,categorie);
			if(qte>0)
				AjoutArticle(Liste_stock_dispo, newArticle);
			else
				AjoutArticle(Liste_stock_epuise, newArticle);
		}
		fclose(f);		//	Fermeture du fichier
		printf("\n\nLe fichier a ete lu avec succes !\n");
	}
}

int IdPresent(int id){
	ListeArticles pointeur = Liste_stock_dispo;
	while(pointeur->nextArticle != Liste_stock_dispo){
		if(id == pointeur->nextArticle->id)
			return 1;
		pointeur=pointeur->nextArticle;
	}
	pointeur = Liste_stock_epuise;
	while(pointeur->nextArticle != Liste_stock_epuise){
		if(id == pointeur->nextArticle->id)
			return 1;
		pointeur=pointeur->nextArticle;
	}
	return 0;
}

int IdPresentStock(int id, ListeArticles Stock){
	ListeArticles pointeur = Stock;
	while(pointeur->nextArticle != Stock){
		if(id == pointeur->nextArticle->id)
			return 1;
		pointeur=pointeur->nextArticle;
	}
	return 0;
}


void viderBuffer(void)
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}