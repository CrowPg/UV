//
//  ev_1j_duree.h
//  TD04
//
//  Created by Johan Medioni on 16/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD04_ev_1j_duree_h
#define TD04_ev_1j_duree_h
#include "Ev_1j.h"

namespace TIME
{
    class Ev_1j_dur: public Ev_1j
    {
    protected:
        Horaire _debut;
        Duree _duree;
    public:
        
        Ev_1j_dur(unsigned int j=0, unsigned int m=0, unsigned int a=0, const string& objet="", unsigned int debutH=0, unsigned int debutM=0, unsigned int dureeH=0, unsigned int dureeM=0):Ev_1j(j, m, a, objet), _debut(Horaire(debutH, debutM)), _duree(Duree(dureeH, dureeM)){}
        
        const Horaire& getdebut() const
        {
            return _debut;
        }
        const Duree& getduree() const
        {
            return _duree;
        }
        void setDebut(const Horaire& h)
        {
            _debut = h;
        }
        void setDuree(const Duree & d)
        {
            _duree = d;
        }
        void afficher(ostream& os) const
        {
            Ev_1j::afficher(os);
            os << "début : " << _debut << " durée : " << _duree << endl;
        }
    };
}


#endif
