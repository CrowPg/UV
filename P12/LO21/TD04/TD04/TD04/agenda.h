//
//  agenda.h
//  TD04
//
//  Created by Johan Medioni on 16/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD04_agenda_h
#define TD04_agenda_h
#include "Ev_1j.h"


namespace TIME
{
    class Agenda
    {
        unsigned int taille;
        unsigned int capacite;
        Ev_1j** tab;
        
    public:
        explicit Agenda(int _tailleMax=10):taille(0), capacite(_tailleMax), tab(new Ev_1j*[capacite]){}
        Agenda(const Agenda& a)
        {
            taille=a.taille;
            capacite=a.capacite;
            tab=new Ev_1j*[capacite];
            for(int i=0 ; i<taille ; i++)
            {
                tab[i]=a.tab[i];
            }
        }
        Agenda& operator=(const Agenda& a)
        {
            taille=a.taille;
            capacite=a.capacite;
            tab=new Ev_1j*[capacite];
            for(int i=0 ; i<taille ; i++)
            {
                tab[i]=a.tab[i];
            }
            
            return *this;
        }
        ~Agenda()
        {
            delete[] tab;
        }
        void afficher(ostream& os = cout)
        {
            os << "-------------AGENDA------------" << endl;
            for (int i=0 ; i<taille ; i++)
            {
                os << *tab[i];
            }
            os << "------------------------------" << endl;
            
        }
        void operator<<(Ev_1j& e);
    };
}


#endif
