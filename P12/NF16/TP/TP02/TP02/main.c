//
//  main.c
//  TP02
//
//  Created by Johan Medioni on 01/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>
#define DIM 10 
typedef float ligne[DIM]; 
typedef ligne matrice[DIM]; 
typedef float *pointeur; 
long nb_appels; 

long int fact1(int n);
long int fact2(int n);
void lecture(matrice t, int lig);
void affiche(matrice t, int l);
void copiesauflc(matrice source, matrice dest, int dim, int ligavirer);
float determinant(matrice m, int dim);
long int fibo1 (int i) ;
int fibo2 (int i);

long int fact1(int n)
{
    long int res=1;
    int i;
    for (i=1; i<=n; i++) 
    {
        res=res*i;
    }
    return res;
}

long int fact2(int n)
{
    long int res=1;
    if (n==0)
    {
        res=1;
    }
    else
    {
        res=n*fact2(n-1);
    }
    
    
    return res;
}


void lecture(matrice t, int lig) /* lit une matrice (au clavier) */
{
    int l,c; float f; 
    puts("dimension de la matrice ?"); 
    scanf("%d",&lig); 
    for (l=0;l< lig;l++) for(c=0;c< lig;c++) 
    {
        printf("élément [%d,%d] ? ",l,c); 
        scanf("%f",&f); 
        t[l][c]=f; 
    }
}
void affiche(matrice t, int l) 
/* affichage du tableau ligne par ligne*/
{
    int i,j; 
    for(i=0;i<l;i++) 
    {
        printf("ligne %d : ",i); 
        for(j=0;j<l;j++) 
            printf("%3.1f ",t[i][j]); 
        printf("\n"); 
    }
}
void copiesauflc(matrice source, matrice dest, int dim, int ligavirer) 
{
    int l,c,ld=0; 
    for (l=0;l<dim;l++) if (l!=ligavirer) 
    {
        for (c=1;c<dim;c++) 
            dest[ld][c-1]=source[l][c]; 
        ld++; 
    }
}
float determinant(matrice m, int dim) 
{
    matrice sous_m; 
    int l,signe=1; 
    float det=0; 
    nb_appels++; 
    if (dim==1) return(m[0][0]); 
    for(l=0;l<dim;l++) 
    {
        copiesauflc(m,sous_m,dim,l); 
        det+=signe*m[l][0]*determinant(sous_m,dim-1); 
        signe=-signe; 
    }
    return(det); 
    
}

long int fibo1 (int i)
{
    if (i==0)
    {
        return 0;
    }
    else if (i==1)
    {
        return 1;
    }
    else
    {
        return (fibo1(i-1)+fibo1(i-2));
    }
}



int main (int argc, const char * argv[])
{
   
}