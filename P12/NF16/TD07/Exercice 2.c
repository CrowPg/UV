void Josephus(int *n, int m);
void decalageGauche(int t[], int *taille, int position);
int* tabJosephus(int n);

void decalageGauche(int t[], int *taille, int position){
	int i;
	for (i=position ; i<*taille-1 ; i++){
		t[i]=t[i+1];
	}
    (*taille)--;
}

int* tabJosephus(int n){
	int *t;
    int i;
	t=(int*)malloc(n*sizeof(int));
	for (i=0 ; i<n-1 ; i++){
		t[i]=i+1;
	}
    return t;
}

void Josephus(int *n, int m){
	int *t;
	t=tabJosephus(*n);
	while(*n>1){
		printf(" %d", t[m-1]);
		decalageGauche(t, n, m-1);
		if (m+m>(*n)){
			m=m+m-(*n);
		}
		else{
			m=m+m;
		}
	}
}