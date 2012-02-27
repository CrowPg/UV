//
//  header.h
//  TP01
//
//  Created by Johan on 27/02/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TP01_header_h
#define TP01_header_h

int g();
void exercice_1();
int f(int x);
void exercice_2();
const double pi=3.14159;
const int MAX=10;
typedef struct Duree
{
    unsigned int h;
    unsigned int m;
} Duree ;
Duree exercice_3();
Duree sum(Duree *x, int n);

#endif
