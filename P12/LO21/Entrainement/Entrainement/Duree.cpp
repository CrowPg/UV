//
//  Duree.cpp
//  Entrainement
//
//  Created by Johan Medioni on 24/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Duree.h"

using namespace std;

Duree::Duree(int h, int m, int s) : m_heures(h), m_minutes(m), m_secondes(s) 
{
    if (m_secondes>=60) 
    {
        m_minutes+=m_secondes/60;
        m_secondes=m_secondes%60;
    }
    if (m_minutes>=60) 
    {
        m_heures+=m_minutes/60;
        m_minutes=m_minutes%60;
    }
}

void Duree::setH(int h){this->m_heures=h;}
void Duree::setM(int m){this->m_minutes=m;}
void Duree::setS(int s){this->m_secondes=s;}
int Duree::getH()const{return m_heures;}
int Duree::getM()const{return m_minutes;}
int Duree::getS()const{return m_secondes;}

Duree& Duree::operator+=(Duree const& d)
{
    m_heures+=d.m_heures;
    m_minutes+=d.m_minutes;
    m_secondes+=d.m_secondes;
    
    if (m_secondes>=60)
    {
        m_minutes+=m_secondes/60;
        m_secondes%=60;
    }
    if (m_minutes>=60)
    {
        m_heures+=m_minutes/60;
        m_minutes%=60;
    }
    
    return *this;
}

Duree operator+(Duree const& d1, Duree const& d2)
{
    Duree copie(d1);
    copie += d2;
    return copie;
}

Duree& Duree::operator-()
{
    m_minutes=-m_minutes;
    m_secondes=-m_secondes;
    m_heures=-m_heures;
    return *this;
}

Duree& Duree::operator-=(const Duree &d)
{
    Duree copy=d;
    *this+=(-copy);
    return *this;
}

Duree operator-(Duree const &d1, Duree const &d2)
{
    Duree copy=d2;
    return d1+(-copy);
}

Duree& Duree::operator*=(int const n)
{
    Duree copy(*this);
    for (int i=1 ; i<n ; i++)
    {
        *this+=copy;
    }
    return *this;
}

Duree operator*(Duree const &d, int const n)
{
    Duree copy(d);
    copy*=n;
    return copy;
}

void Duree::afficher(ostream &f)const
{
    f<<m_heures<<"h"<<m_minutes<<"m"<<m_secondes<<"s"<<endl;
}

std::ostream& operator<<(std::ostream& f, Duree const &d)
{
    d.afficher(f);
    return f;
}

bool Duree::estEgal(Duree const& b) const
{
    //Teste si a.m_heure == b.m_heure etc.  
    if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes)
        return true;
    else
        return false;
}

bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures < b.m_heures)
        return true;
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes)
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes)
        return true;
    else
        return false;
}

bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}


bool operator!=(Duree const& a, Duree const& b)
{
    if(a == b)         //On utilise l'opérateur == qu'on a défini précédemment !
        return false;  //Si ils sont égaux, alors ils ne sont pas différents
    else
        return true;   //Et si ils ne sont pas égaux, c'est qu'ils sont différents ;-)
}


bool operator<(Duree const &a, Duree const& b)
{
    if(a.estPlusPetitQue(b))
        return true;
    else
        return false;
}

bool operator>(Duree const &a, Duree const &b)
{
    if (a<b) return false;
    else return true;
}

bool operator<=(Duree const &a, Duree const &b)
{
    if ((a<b) || (a==b)) return true;
    else return false;
}

bool operator>=(Duree const &a, Duree const &b)
{
    if ((a>b) || (a==b)) return true;
    else return false;
}