//
//  banque.h
//  TP02
//
//  Created by Johan Medioni on 26/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TP02_banque_h
#define TP02_banque_h

#include <string.h>
#include <vector>

#include "Compte.h"
#include "TypeCompte.h"
#include "Client.h"
#include "Operation.h"

using namespace banque;

namespace banque
{
    class Banque    
    {
    public:
        std::string nom;
        std::vector<Compte> comptes;
        std::vector<TypeCompte> typesComptes;
        std::vector<Client> clients;
    
    public:
        void Initialiser (std::string);
        
        void CreerUnTypeDeCompte(std::string type, double min, double max, float taux);
        
        void AjouterUnClient(std::string prenom, std::string nom, int jour, int mois, int annee);
        
        void CreerUnCompte(std::string type, std::string prenom, std::string nom, double solde_dep);
        
        Compte GetCompte(std::string type, std::string prenom, std::string nom);
        
        void Afficher();
    };
}


#endif