//
//  Duree.h
//  Entrainement
//
//  Created by Johan Medioni on 24/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Entrainement_Duree_h
#define Entrainement_Duree_h


class Duree
{
public:
    
    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    void setH(int h);
    void setM(int m);
    void setS(int s);
    int getH() const;
    int getM() const;
    int getS() const;
    void afficher(std::ostream &flux) const;
    Duree& operator+=(Duree const &d);
    Duree& operator-();
    Duree& operator-=(Duree const &d);
    Duree& operator*=(int const nombre);
    
    bool estEgal(Duree const& b) const;
    bool estPlusPetitQue(Duree const& b) const;
    
private:
    
    int m_heures;
    int m_minutes;
    int m_secondes;
};

Duree operator+(Duree const &d1, Duree const &d2);
Duree operator-(Duree const &d1, Duree const &d2);
Duree operator*(Duree const &d, int const nombre);

std::ostream& operator<<(std::ostream& f, Duree const &d); 

bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
bool operator<(Duree const& a, Duree const& b);
bool operator>(Duree const& a, Duree const& b);
bool operator<=(Duree const& a, Duree const& b);
bool operator>=(Duree const& a, Duree const& b);

#endif
