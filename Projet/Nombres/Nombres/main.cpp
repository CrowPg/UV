//
//  main.cpp
//  Nombres
//
//  Created by Johan Medioni on 04/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "Rationnel.h"

using namespace std;

int main (int argc, const char * argv[])
{

    try{
        Rationnel r(2,0);
    }
    
        catch(Erreur const& e)
    {
        e.afficher();
    }
}

