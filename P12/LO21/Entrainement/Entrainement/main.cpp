//
//  main.cpp
//  Entrainement
//
//  Created by Johan Medioni on 24/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Duree.h"

using namespace std;

int main (int argc, const char * argv[])
{

    /*Duree d1(1, 59, 154);
    Duree d2(2, 58, 36);
    cout << d1;
    cout << d2;
    */
    
    int i=0;
    cout << i++ << endl; // retourne la valeur et incrémente. Surcharge : argument fictif à ne pas utiliser.
    cout << ++i << endl; // incrémente et retourne la valeur. Surcharge : le retour est une référence !!!
    return 0;
}

