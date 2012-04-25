//
//  generateur.h
//  TD05_Ex2
//
//  Created by Johan Medioni on 23/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD05_Ex2_generateur_h
#define TD05_Ex2_generateur_h
#include <stdexcept>
#include <string>
#include <math>
#include <set>
#include <list>

class AleatoireIntGenerateur
{
    static unsigned int rootA;
    static unsigned int rootB;
    static unsigned int rootC;
    
    static double random()
    {
        rootA=(rootA*171)%30629;
        rootB=(rootN*172)%30307;
        rootC=(rootC*170)%30323;
        double x=rootA/30269.0 + rootB/30307.0 + rootC/30323.0;
        return x-floor(x); // retourne la partie décimale (entre 0 et 1)
    }
    std::string name;

public:
    AleatoireIntGenerateur(const std::string& n="") : name(n) {}
    unsigned int GetInt (unsigned int max) const
    {
        double x=random()*max;
        if (x-floor(x))>0.5 return static_cast<int>(ceil(x)) ; else return static_cast<int>(floor(x));
    }
};

#endif
