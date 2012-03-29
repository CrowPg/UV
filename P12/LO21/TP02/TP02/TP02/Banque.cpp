//
//  bancque.cpp
//  TP02
//
//  Created by Johan Medioni on 26/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "Compte.h"
#include "TypeCompte.h"
#include "Client.h"
#include "Operation.h"
#include "Banque.h"

using namespace banque;

void banque::Banque::Initialiser(std::string nom)
{
    this->nom = nom;
}

void Banque::CreerUnTypeDeCompte(std::string type, double min, double max, float taux)
{
    TypeCompte t;
    t.nom = type;
    t.soldeMax = max;
    t.soldeMin = min;
    t.taux = taux;
    this->typesComptes.push_back(t);
}

void Banque::AjouterUnClient(std::string prenom, std::string nom, int jour, int mois, int annee)
{
    Client c;
    c.nom = nom;
    c.prenom = prenom;
    c.jour = jour;
    c.mois = mois;
    c.annee = annee;
    this->clients.push_back(c);

} // Traiter les cas d'erreurs.

void Banque::CreerUnCompte(std::string type, std::string prenom, std::string nom, double solde_dep)
{
    Compte c;
    int i;
    bool test_compte=false, test_client=false;
    if (this->typesComptes.size()>0)
    {
        for (i=0; i<this->typesComptes.size(); i++) 
        {
            if (this->typesComptes[i].nom==type) 
            {
                c.type=this->typesComptes[i];
                test_compte=true;
            }
        }
    }
    if (this->clients.size()>0)
    {
        for (i=0; i<this->clients.size(); i++)
        {
            if ((this->clients[i].nom==nom)&&(this->clients[i].prenom==prenom)) 
            {
                c.client.nom=nom;
                c.client.prenom=prenom;
                c.soldeCourant = solde_dep;
                test_client=true;
            }
        }
    }
    
    if (test_compte==false)
    {
        std::cout << "\nCe type de compte n'existe pas !";
    }
    if (test_client==false) 
    {
        std::cout << "\nCréez d'abord ce client !";
    }
    if ((test_client==true)&&(test_compte==true)) 
    {
        this->comptes.push_back(c);
    }
}



