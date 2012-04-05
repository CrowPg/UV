//
//  Planning.h
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD03_Planning_h
#define TD03_Planning_h

#include "programmation.h"

class Planning
{
    Cinema::Programmation * progs;
    unsigned int taille_Max;
    unsigned int taille;
    
public:
    explicit Planning (int t): progs(new Cinema::Programmation[t]), taille_Max(t), taille(0){}
    ~Planning ()
    {
        delete[] progs;
    }
    bool operator<<(const Cinema::Programmation& p);
    
    class Iterator
    {
        const Cinema::Programmation * prog;
    public:
        const Cinema::Programmation& operator*() const{return * prog;}
        bool operator!=(const Iterator& it) const {if (prog == it.prog) return false; return true;}
        void operator++(){prog++;}
        Iterator(const Cinema::Programmation& p):prog(p){}
        
    };
    Iterator& begin(){return Iterator(progs[0]);}
    Iterator& end(){return Iterator(progs[taille]);}
                                      
};


#endif
