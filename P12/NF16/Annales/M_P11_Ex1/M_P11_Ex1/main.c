//
//  main.c
//  M_P11_Ex1
//
//  Created by Johan Medioni on 28/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int somme(int *tab1,int*tab2);

int somme(int *tab1,int*tab2){
	if (*(tab1+1)==NULL || *(tab2+1)==NULL)
		return (*tab1)+(*tab2);
	else
		return *tab1+*tab2+somme(tab1+1, tab2+1);
}

int main (int argc, const char * argv[]){
	int *tab1, *tab2;
	tab1 = malloc (3*sizeof(int));
	tab2 = malloc (4*sizeof(int));
	int i=0;
	for (i=0 ; i<3 ; i++){
		tab1[i]=1;
		printf("\n case %d de tab1 : %d", i, tab1[i]);
	}
	for (i=0 ; i<4 ; i++){
		tab2[i]=1;
		printf("\n case %d de tab1 : %d", i, tab2[i]);
	}
	printf("\n%d", somme(tab1, tab2));
}