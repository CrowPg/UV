//
//  compte.h
//  TP02
//
//  Created by Johan Medioni on 26/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TP02_compte_h
#define TP02_compte_h

#include "TypeCompte.h"
#include "Client.h"

namespace banque 
{
    class Compte
    {
    public:
        TypeCompte type;
        double soldeCourant;
        Client client;
        
        void Afficher();
        
        void TransfererVers(double montant, Compte compte);
        
        void Depot(double montant, Compte compte);
        
        void retrait(double montant, Compte compte);
        
        friend class Banque;
    };
}

#endif
