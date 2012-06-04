//
//  Header.h
//  Nombres
//
//  Created by Johan Medioni on 04/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Nombres_Header_h
#define Nombres_Header_h

#include "Rationnel.h"
#include "Reel.h"
#include "Constante.h"
#include "Complexe.h"

class Entier : public Constante{
    int val;
    
public:
    void afficher(){
        std::cout << "\n" << val << std::endl;
    }
    
    int getVal(){
        return val;
    }
    
    operator Reel(){
        return Reel((double) val);
    }
    
    operator Rationnel(){
        return Rationnel(val, 1);
    }
    
    operator Complexe(){
        return Complexe((double)val, 0);
    }
}

#endif
