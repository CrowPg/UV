//
//  main.cpp
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "film.h"

using namespace Cinema;

int main (int argc, const char * argv[])
{
    Film f;
    f.Afficher();
    Duree d = Duree(1, 30);
    d.Afficher();
    f.setDuree(d);
    f.setTitre("Film1");
    f.Afficher();
}

