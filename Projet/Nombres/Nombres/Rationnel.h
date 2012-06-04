//
//  Rationnel.h
//  Nombres
//
//  Created by Johan Medioni on 04/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Nombres_Rationnel_h
#define Nombres_Rationnel_h

#include "Constante.h"
#include "Reel.h"
#include "Complexe.h"

class Rationnel : public Constante{
    int num;
    int den;
    
public:
    Rationnel(int n, int d) {
        if (d==0)
            throw Erreur(1, "Nombre infini");
        else
            num=n;
            den=d;
    }
    
    
    int getNum(){
        return num;
    }
    int getDen(){
        return den;
    }
    
    operator Reel(){
        return Reel(num/den);
    }
    operator Complexe(){
        return Complexe((double)num/(double)den, 0);
    }
    
    void afficher();
    
};



#endif
