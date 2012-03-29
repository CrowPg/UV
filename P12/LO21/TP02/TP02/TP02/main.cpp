//
//  main.cpp
//  TP02
//
//  Created by Johan Medioni on 26/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Compte.h"
#include "TypeCompte.h"
#include "Client.h"
#include "Operation.h"
#include "Banque.h"
#include "banque.h"

using namespace banque;

int main (int argc, const char * argv[])
{
    Banque BNP;
    
    BNP.Initialiser("BNP");
    std::cout << "\n BNP.nom : " << BNP.nom;
    
    BNP.CreerUnTypeDeCompte("CHEQUE", -500, 15000, 0);
    std::cout << "\n BNP.typeComptes : " << BNP.typesComptes[0].nom;
    
    BNP.AjouterUnClient("Jean", "Moulin", 3, 7, 1990);
    std::cout << "\n BNP.clients : " << BNP.clients[0].prenom << " " << BNP.clients[0].nom;
    
    BNP.CreerUnCompte("CHEQUE", "Jean", "Moulin", 750);
    std::cout << "\n Nouveau Compte : " << BNP.comptes[0].client.prenom << " " << BNP.comptes[0].client.nom << " : " << BNP.comptes[0].type.nom << " : " << BNP.comptes[0].soldeCourant;
    
    return 0;
}

