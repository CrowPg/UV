//
//  header.h
//  TD01
//
//  Created by Johan Medioni on 12/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD01_header_h
#define TD01_header_h


struct essai 
{
    int n;
    float x; 
};

struct compte {
    char id[20];
    int solde; };

namespace TD1
{
    char *strcpy(char *dest, const char * dep);
    void inverse(int *a, int *b);
    void inverse(int &a, int &b);
    void raz(essai* es);
    void raz(essai& pt);
    
    int& operation(compte* tab, const char* nom);
}

void essai_alloc();
void essai_alloc_mod();
void exercice_1();

void truc1(int& x);
void truc2(int& x);
void truc3(int& x);

int fct(int x);
int fct(float  y);
int fct(int x, float  y);
float fct(float x, int  y);
void exercice6();


#endif
