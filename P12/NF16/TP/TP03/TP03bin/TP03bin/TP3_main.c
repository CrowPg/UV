#include "TP3.h"

int main(){
	ListeRequetes l=(ListeRequetes)malloc(sizeof(Requete));
    l->nextRequete=l;
    Requete *r1, *r2, *r3;
    r1=(Requete*)malloc(sizeof(Requete));
    r2=(Requete*)malloc(sizeof(Requete));
    r3=(Requete*)malloc(sizeof(Requete));
    AjoutRequete(l, r1);
    AjoutRequete(l, r2);
    AjoutRequete(l, r3);
    
    

	return 0;
}