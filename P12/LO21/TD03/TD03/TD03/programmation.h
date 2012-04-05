//
//  programmation.h
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD03_programmation_h
#define TD03_programmation_h
#include "time.h"
#include "film.h"

namespace Cinema
{
    class Programmation
    {
        TIME::Intervalle inter;
        const Film* film;
    
    public:
        Programmation (TIME::Date _deb=TIME::Date(),  TIME::Date _fin=TIME::Date(), const Film * _film = 0) : inter(TIME::Intervalle(_deb, _fin)), film(_film){}
    
    };
}


#endif
