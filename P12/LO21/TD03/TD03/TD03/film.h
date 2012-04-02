//
//  film.h
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD03_film_h
#define TD03_film_h

#include<iostream>
#include <string>
#include "time.h"

using namespace TIME;

namespace Cinema
{
    class Film
    {
        std::string titre;
        Duree duree;
        
    public:
        Film(const std::string _titre=" ", int _duree=0) : titre(_titre), duree(Duree(_duree)){}
        ~Film(){}
        std::string getTitre() const
        {
            return titre;
        }
        Duree getDuree() const
        {
            return duree;
        }
        void setTitre(const std::string &titre)
        {
            this->titre=titre;
        }
        void setDuree(const Duree &duree)
        {
            this->duree=duree;
        }
        void Afficher(std::ostream &os=std::cout)
        {
            os<<titre<<"("<<duree<<")";
        }
    };
}




#endif
