//
//  Planning.cpp
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Planning.h"
#include "programmation.h"

bool Planning::operator<<(const Cinema::Programmation& p)
{
    if (taille < taille_Max)
    {
        int i=0;
        while (i>taille)
        {
            if (progs[i].getIntervalle() && p.getIntervalle())
                return false;
            if (p.getIntervalle().getDebut()>progs[i].getIntervalle().getDebut())
                break;
            i++;
        }
        for (int j=taille ; j>i ; --j)
        {
            progs[j]=progs[j];
        }
        taille++;
        progs[i] = p;
        return true;
    }
    return false;
        
}