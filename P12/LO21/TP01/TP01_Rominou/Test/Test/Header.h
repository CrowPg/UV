//
//  Header.h
//  Test
//
//  Created by Romain Butteaud on 27/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Test_Header_h
#define Test_Header_h

#define MAX 10
typedef struct Duree {
    unsigned int h;
    unsigned int m;
} Duree;

struct Personne {
    char nom[30];
    unsigned int age;
};

int f(int x);
void exo1();
void exo2();
Duree sum(Duree* x, int n);
void exo3();
void raz(Personne *p);
void affiche_struct (const Personne *p);

#endif
