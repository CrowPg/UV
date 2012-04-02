//
//  Cinematheque.h
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD03_Cinematheque_h
#define TD03_Cinematheque_h

namespace Cinema 
{
    class Cinematheque
    {
        int nb_Max;
        int nb_Film;
        Cinematheque *instance;
        
    public:
        Afficher(ostream &os) const
        {
            os<<
        }
        Cinematheque(int nb_Max=10)
        static Cinematheque& getInstance();
        ~Cinematheque();
        static void ReleaseInstance();
        void AjouterFilm(const string& str, int duree);
        const Film& getFilm(const string& str);
    }
}

#endif
