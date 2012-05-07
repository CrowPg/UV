typedef struct Pile{
	int *tab;
	int s;
	int MAX;
}

Pile* Créer pile(int max){
	pile *p=malloc(sizeof(Pile));
	pile->s=0;
	pile->MAX=max;
	pile->tab=malloc(MAX*sizeof(int));
	return p;
}

int Pile_vide(Pile p){
	if (p.s==0)
		return 1;
	else
		return 0;
}

void empiler(int val, Pile* p){
	if (p->s<p->Max){
		p->s++;
		p->tab[p->s]=val;
	}
	else printf("erreur de débordement par excès");
}

int depiler(Pile* p){
	if (pile_vide){
		printf("erreur de débordement pas défaut");
	}
	else{
		p->s--;
		return p->tab[p->s+1];
	}