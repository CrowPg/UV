#include "TP3.h"








int main(){
	int choix=1;
	printf("#####\t\tTP3 - Liste Chainees\t\t#####\n###\tARZOUNIAN Jean-Baptiste & MEDIONI Johan\t###\n\n\n");
	Liste_stock_dispo=CreerListe();
	Liste_stock_epuise=CreerListe();
	int qte=-1, id;
	float PU=-1;
	char libelle[50];
	char categorie[50];
	char* positionEntree=NULL;
	Article *a=NULL;
	while(choix != 15){
		printf("*****\t\tMenu\t\t*****\n\n");
		printf("1. Lecture des donnees a partir du fichier 'stock.txt'\n2. Ajout d'un nouvel article non existant dans le magasin a partir du clavier\n\n3. Affichage des caracteristiques des articles du stock\n\t4. Stock disponible\n\t5. Stock epuise\n\t6. Tout le stock\n7. Suppression d'un article\n8. Recherches d'articles\n\t9. Recherche par identifiant, libelle et/ou categorie\n\t10. Recherche par quantite\n\t11. Recherche par prix unitaire\n12. Gestion des commandes clients (saisies au clavier)\n13. Approvisionner le stock (saisies au clavier)\n14. Suppression du stock\n15. Quitter\n\nVotre choix: ");
		/*	Saisie Sécurisée	*/
		do{
			if(scanf("%d",&choix) != 1){							//Si la saisie n'est pas un entier
				printf("\nERREUR: Veuillez saisir un entier\n");
				/* vidage du buffer */
				scanf ("%*[^\n");
				getchar ();
			}
			else if(choix < 1 || choix > 15)
				printf("\nERREUR : Choix incorrect\n\nVotre choix: ");
		}while(choix < 1 || choix > 15);
		switch(choix){
			case 1:
				LireFichier("stock.txt");
				system("pause");
				break;
			case 2:
				do{
					printf("\nQuel est le nom de l'article : ");
					viderBuffer();
					fgets(libelle,50,stdin);
					positionEntree = strchr(libelle, '\n');
					if (positionEntree != NULL){
						*positionEntree = '\0';
					}
					if(positionEntree == NULL)
						printf("\nERREUR : libelle trop long (max 50 caracteres)!!\n");
				}while(positionEntree == NULL);
                
				do{
					printf("Combien en avez-vous : ");
					if(scanf("%d",&qte) != 1){	 //Si la saisie n'est pas un entier
						printf("\nERREUR: Veuillez saisir un entier strictement positif\n");
						/* vidage du buffer */
						scanf ("%*[^\n");
						getchar ();
					}
					else if(qte<0)
						printf("\nERREUR : la quantite doit etre >= 0 !\n");
				}while(qte<0);
				
				do{
				    printf("Quel est son prix : ");
					if(scanf("%f",&PU) != 1){	 //Si la saisie n'est pas un rŽel
						printf("\nERREUR: Veuillez saisir un nombre reel\n");
						/* vidage du buffer */
						scanf ("%*[^\n");
						getchar();
					}
					else if(PU<0)
						printf("\nERREUR : le prix doit etre >= 0\n");
				}while(PU<0);
                
				do{
					printf("Quelle est sa catŽgorie : ");
					viderBuffer();
					fgets(categorie,50,stdin);
					positionEntree = strchr(categorie, '\n');
					if (positionEntree != NULL){
						*positionEntree = '\0';
					}
					if(positionEntree == NULL)
						printf("\nERREUR : categorie trop longue (max 50 caracteres)!!\n");
				}while(positionEntree == NULL);
				
				do{
					printf("Quel est son identifiant : ");
					if(scanf("%d",&id) != 1){	 //Si la saisie n'est pas un entier ou si l'identifiant est dŽjˆ utilisŽ
						printf("\nERREUR: Veuillez saisir un entier\n");
						/* vidage du buffer */
						scanf ("%*[^\n");
						getchar ();
					}
					else if(IdPresent(id)==1)
						printf("\nERREUR : cet ID est deja present dans le stock, veuillez en choisir un autre\n");
				}while(IdPresent(id)!=0);
				
				a=CreerArticle(id, libelle, PU, qte, categorie);
				printf("%d, %s, %.2f, %d, %s",id,libelle,PU,qte,categorie);
				if(qte>0) 
					AjoutArticle(Liste_stock_dispo,a);
				else
					AjoutArticle(Liste_stock_epuise,a);
                AfficherArticle(a);
				break;
			case 3:
                printf("\n4. Afficher le stock dispo.\n5. Afficher le stock epuise.\n5. Afficher tout le stock. \nRetour au programme principal.\n");
				break;
			case 4:
				AfficheStock(Liste_stock_dispo);
				system("pause");
				break;
			case 5:
				AfficheStock(Liste_stock_epuise);
				system("pause");
				break;
			case 6:
                AfficheStock(Liste_stock_dispo);
                AfficheStock(Liste_stock_epuise);
				break;
			case 7:
                printf("Quel est l'identifiant de l'article que vous voulez supprimer ?");
                do{
					printf("Quel est son identifiant : ");
					if(scanf("%d",&id) != 1){	 //Si la saisie n'est pas un entier
						printf("\nERREUR: Veuillez saisir un entier\n");
						/* vidage du buffer */
						scanf ("%*[^\n");
						getchar ();
					}
					else if(IdPresent(id)==0)
						printf("\nERREUR : cet ID est deja present dans le stock, veuillez en choisir un autre\n");
				}while(IdPresentStock(id, Liste_stock_dispo)!=0); //Tant que l'article est absent du stock disponible.
                SupprimeArticle(Liste_stock_dispo, id);
				break;
                system("pause");
			case 8:
                printf("\n9. Recherche par identifiant, libelle et/ou categorie\t10. Recherche par quantite\t11. Recherche par prix unitaire\n Retour au programme principal.\n");
				break;
			case 9:
                
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				break;
			case 14:
				break;
			case 15:
				LibererListe(Liste_stock_dispo);
				LibererListe(Liste_stock_epuise);
				printf("\n\n\n*****\t\tFin du Programme\t\t*****\n\n");
				break;
			default:
				printf("\nERREUR\n");
				break;
		}
	}
	return 0;
}