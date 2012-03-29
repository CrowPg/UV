//
//  TypeCompte.h
//  TP02
//
//  Created by Johan Medioni on 26/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TP02_TypeCompte_h
#define TP02_TypeCompte_h

namespace banque
{
    class TypeCompte
    {
    public:
        std::string nom;
        float taux; // : float
        double soldeMin;// : double
        double soldeMax;// : double
        
        void Afficher();
        
        friend class Banque;
    };
}


#endif
