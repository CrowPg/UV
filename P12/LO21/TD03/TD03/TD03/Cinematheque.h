//
//  Cinematheque.h
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD03_Cinematheque_h
#define TD03_Cinematheque_h
#include "film.h"

namespace Cinema 
{
    class Cinematheque
    {
        unsigned int nb_Max;
        unsigned int nb_Film;
        static Cinematheque *instance;
        Film** tab; //une adresse qui pointe vers une autre adresse qui pointe sur un film
        
    public:
                
        static Cinematheque& getInstance();
        static void ReleaseInstance();
        void AjouterFilm(const std::string& titre, int duree);
        const Film& getFilm(const std::string& str);
        void Afficher(std::ostream& os=std::cout) const
        {
            for (int i=0 ; i<nb_Film ; ++i)
                os << *tab[i]<<endl;
        }
    private:
        Cinematheque(int n=10) : nb_Max(n), nb_Film(0), tab(new Film*[n]){}
        ~Cinematheque()
        {
            for (int i=0 ; i<nb_Film ; ++i) delete tab[i];
            delete[] tab;
        }// singleton => le constructeur et le destructeur doivent être privés
        Cinematheque& operator=(const Cinematheque& c)
        {
            return *this;
        } // encore pour le singleton
        
        
    };
}

#endif
