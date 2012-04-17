//
//  RdV.h
//  TD04
//
//  Created by Johan Medioni on 16/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD04_RdV_h
#define TD04_RdV_h
#include "Ev_1j_dur.h"

namespace TIME 
{
    class RdV: public Ev_1j_dur
    {
    protected:
        string _lieu;
        string _personne;
    public:
        RdV(unsigned int j=0, unsigned int m=0, unsigned int a=0, const string& objet ="", unsigned int debutH=0, unsigned int debutM=0, unsigned int dureeH=0, unsigned int dureeM=0, const string& lieu="", const string& personne=""): Ev_1j_dur(j, m, a, objet, debutM, dureeH, dureeM), _lieu(lieu), _personne(personne){}
        
        const string& getPersonne() const
        {
            return _personne;
        }
        const string& getLieu() const
        {
            return _lieu;
        }
        void setLieu(const string& l)
        {
            _lieu=l;
        }
        void setPersonne(const string& p)
        {
            _personne=p;
        }
        void afficher(ostream& os)
        {
            Ev_1j_dur::afficher(os);
            os << "Avec : " << _personne << ", lieu : " << _lieu << endl; 
        }
    };
}

#endif
