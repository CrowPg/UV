//
//  Cinematheque.cpp
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Cinematheque.h"
#include "Header.h"

using namespace Cinema;

Cinematheque* Cinematheque::instance=0; //initialisiation d'un membre statique

Cinematheque& Cinematheque::getInstance()
{
    if(instance == 0)
        instance  = new Cinematheque();
    return *instance;
}

void Cinematheque::AjouterFilm(const std::string& titre, int duree)
{
    if (nb_Film == nb_Max)
    {
        Film ** tmp = new Film*[nb_Max+10];
        for (int i =0 ; i<nb_Max ; ++i) 
        {
            tmp[i]=tab[i];
        }
        delete[] tab;
        tab=tmp;
        nb_Max+=10;
    }
    tab[nb_Film++] = new Film(titre, duree);
}


const Film& Cinematheque::getFilm(const std::string& str)
{
    for (int i=0 ; i<nb_Film ; ++i) 
    {
        if (tab[i]->getTitre()==str)
            return *tab[i];
        
    }
    throw CinemaException ("Erreur, ce filme n'existe pas");

}