//
//  main.cpp
//  TD01
//
//  Created by Johan Medioni on 12/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include "header.h"

using namespace std;

char * TD1::strcpy(char *dest, const char * dep) /* 
                                                  1. utilité du const : on ne peut pas changer la zone pointée par le pointeur via lui-même (pointeur const) => + de sécurité
                                                  2. TD1::strcpy : pour que la fonction créée soit dans le namespace TD1 (TD1 a été déclaré dans le header, et strcpy dans ce namespace au sein du header)
                                                  */
{
    int i;
    for (i=0 ; dep[i]!='\0' ; i++) /* important de ne pas utiliser for (int i...), sinon on ne peut pas l'utiliser dans la boucle !!! */ 
    {
        dest[i]=dep[i];
    }
    return dest;
}

void exercice_1()
{
    char dep[20]="Miaou";
    char dest[20]="Ouaff";
    cout << dep << "\n";
    cout << dest << "\n";
    TD1::strcpy(dest, dep);
    cout << dep << "\n";
    cout << dest << "\n";
}

void essai_alloc()
{
    int* pt_int;
    double* pt_double;
    pt_int=(int*)malloc(sizeof(int));
    pt_double=(double*)malloc(sizeof(double)*100);
    free(pt_int);
    free(pt_double);
}

void essai_alloc_mod()
{
    int* pt_int;
    double* pt_double;
    pt_int=(int*)new int;
    pt_double=(double*)new double[100];
    delete pt_int;
    delete[] pt_double;
}

void TD1::inverse(int *a, int *b)
{
    int pt = *a;
    *a = *b;
    *b = pt;
}

void TD1::inverse(int& a, int& b)/* principe de la surcharge*/
{
    int c=a;
    a=b;
    b=c;
}

void TD1::raz(essai& es)
{
    es.x=0;
    es.n=0;
}

void TD1::raz(essai* es)
{
    es->x=0;
    es->n=0;
}

/*
 void truc1(const int& x){
    std::cout<<x<<"\n";
    x++; // const empêche de changer ce qui est pointé par la référence (c'est ce qu'on fait là effectivement) => il faut enlever 
    std::cout<<x<<"\n";
 }
*/

void truc1(int& x){
    std::cout<<x<<"\n";
    x++;
    std::cout<<x<<"\n";
}

void truc2(int& x)
{
    x++;
    truc1(x);
    x++; 
}

/*
 void truc3(const int& x) //le const, c'est pas bon puisqu'on appelle truc2 après
 {
    truc2(x);
    double y=x; //pas possible car x est un int
    double& z=x;
    double& u=y;
    double& t=y-3;
 }
*/

void truc3(int& x)
{
    truc1(x);
    int y=x;
    double a = x;
    double& z=a;
    double& u=a;
    double& t=a;
}

/*
 int fct(int x){ std::cout<<"1:"<<x<<"\n"; return 0; }
 int fct(float  y){ std::cout<<"2:"<<y<<"\n"; return 0; }
 int fct(int x, float  y){ std::cout<<"3:"<<x<<y<<"\n"; return 0; }
 float fct(float x, int  y){ std::cout<<"4:"<<x<<y<<"\n"; return 3.14; }
 void exercice6(){
 int i=3,j=15;
 float x=3.14159,y=1.414;
 char c='A';
 double z=3.14159265;
 fct(i); //appel 1
 fct(x); //appel 2
 fct(i,y); //appel 3
 fct(x,j); //appel 4
 fct(c); //appel 5
 fct(i,j); //appel 6
 fct(i,c); //appel 7
 fct(i,z); //appel 8
 fct(z,z); //appel 9
 }
 //Il faut forcer les types des convertions implicites ambiguës
*/

int fct(int x){ std::cout<<"1:"<<x<<"\n"; return 0; }
int fct(float  y){ std::cout<<"2:"<<y<<"\n"; return 0; }
int fct(int x, float  y){ std::cout<<"3:"<<x<<y<<"\n"; return 0; }
float fct(float x, int  y){ std::cout<<"4:"<<x<<y<<"\n"; return 3.14; }

void exercice6(){
    int i=3,j=15;
    float x=3.14159,y=1.414;
    char c='A';
    double z=3.14159265;
    fct(i); //appel 1
    fct(x); //appel 2
    fct(i,y); //appel 3
    fct(x,j); //appel 4 
    fct(c); //appel 5
    fct(i,(float)j); //appel 6
    fct(i,(float)c); //appel 7
    fct(i,z); //appel 8
    fct((float)z,(int)z); //appel 9
}

int& TD1::operation(compte* tab, const char* nom)
{
    int i=0;
    while (strcmp (nom, tab[i].id)!=0)
    {
        i++;
    }
    return tab[i].solde;
}
/* strcmp : compare 2 string et donne une valeur correspondant à la différence (si 0, mêmes strings)*/
int main (int argc, const char * argv[])
{
    return 0;
}



