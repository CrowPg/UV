//
//  client.h
//  TP02
//
//  Created by Johan Medioni on 26/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TP02_client_h
#define TP02_client_h

namespace banque 
{
    class Client
    {
    public:
        std::string nom;
        std::string prenom;
        int jour, mois, annee;
        
        void Afficher();
        
        friend class Banque;
    };
}

#endif
