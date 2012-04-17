//
//  agenda.cpp
//  TD04
//
//  Created by Johan Medioni on 16/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "agenda.h"

void TIME::Agenda::operator<<(TIME::Ev_1j& e)
{
    if(taille == capacite)
    {
        Ev_1j** tmp = new Ev_1j*[capacite+10];
        for (int i=0 ; i<taille ; i++)
        {
            tmp[i]=tab[i];
        }
        capacite+=10;
        delete[] tab;
    }
    
    tab[taille++]=&e;
}