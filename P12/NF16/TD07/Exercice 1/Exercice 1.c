#include <stdlib.h>
#include <stdio.h>

void decalageGauche(int t[], int *taille, int position);
int* tabEratosthene(int n);
void afficheTab(int t[], int n);
void cribleEratosthene(int *t, int *n);


void decalageGauche(int t[], int *taille, int position){
	int i;
	for (i=position ; i<*taille-1 ; i++){
		t[i]=t[i+1];
	}
    (*taille)--;
}

int* tabEratosthene(int n){
	int *t;
    int i;
	t=(int*)malloc(n*sizeof(int));
	for (i=0 ; i<n-1 ; i++){
		t[i]=i+2;
	}
    return t;
}

void afficheTab(int *t, int n){
	int i;
	for (i=0 ; i<n ; i++){
		printf(" %d", t[i]);
	}
}

void cribleEratosthene(int *t, int *n){
	t=tabEratosthene(*n);
	int i, b=1;
    int po=-1;
	while(b==1){
        po=po+1;
		b=0;
		for (i=po+1 ; i<*n ; i++){
			if (t[i]%t[po]==0){
				decalageGauche(t, n, i);
				b=1;
			}
		}
        
	}
	afficheTab(t, *n);
}

int main(void){
    int *t;
    int *n;
    int taille=200;
    n=&taille;
    cribleEratosthene(t, n);
    free(t);
   
}