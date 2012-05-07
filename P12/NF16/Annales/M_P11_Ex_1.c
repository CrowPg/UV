int somme(int *tab1,int*tab2);

int somme(int *tab1,int*tab2){
	if ((tab1+1)*==NULL || (tab2+1)*==NULL)
		return tab1*+tab2*;
	else
		return tab1*+tab2*+somme(tab1+1, tab2+1);
}

int main (){
	int *tab1, *tab2;
	tab1 = malloc (3*sizeof(int));
	tab2 = malloc (4*sizeof(int));
	int i=0;
	for (i=0, i<3, i++){
		tab1[i]=1;
		printf("\n case %d de tab1 : %d", i tab[i]);
	}
	for (i=0, i<4, i++){
		tab2[i]=1;
		printf("\n case %d de tab1 : %d", i tab[i]);
	}
	somme(tab1, tab2);
}