#include <stdio.h>
#include <stdlib.h>
//pas bon mais presque

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
    int pos=m;
	t=tabJosephus(*n);
	while(*n>1){
		printf(" %d", t[pos-1]);
		decalageGauche(t, n, pos-1);
		if (pos+m>(*n)){
			pos=pos+m-(*n)-1;
		}
		else{
			pos=pos+m-1;
		}
	}
}



int main (int argc, const char * argv[])
{
    int *n;
    int m=9;
    n=&m;
    Josephus(n, 5);
    
    return 0;
}