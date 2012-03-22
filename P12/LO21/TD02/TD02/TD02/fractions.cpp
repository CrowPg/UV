//
//  fractions.cpp
//  TD02
//
//  Created by Johan Medioni on 19/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "fractions.h"
#include <exception>

using namespace math;

fraction::fraction(int n, int d) : numerateur(n)
{
    if (d==0)
        throw std::exception();
    else
        denominateur=d;
}

fraction::~fraction()
{}

int fraction::get_num() const
{
    return numerateur;
}

int fraction::get_den() const
{
    return denominateur;
}

void fraction::set_num(int n)
{
    numerateur=n;
}

void fraction::set_den(int d)
{
    denominateur=d;
}

void fraction::simplify()
{
    int div=denominateur;
    if (denominateur < 0)
    {
        denominateur=-denominateur;
        numerateur=-numerateur;
    }
    while (div!=1)
    {
        if ((numerateur%div == 0) && (denominateur%div == 0))
        {
            numerateur = numerateur/div;
            denominateur = denominateur/div;
        }
        div--;
    }
}

fraction math::operator+(fraction const &a, fraction const &b)
{
    int num=(a.numerateur*b.denominateur)+(b.numerateur*a.denominateur);
    int den=(a.denominateur*b.denominateur)+(b.denominateur*a.denominateur);
    return fraction(num, den);
}

fraction& fraction::operator++()
{
    numerateur=numerateur+denominateur;
    return (*this);
}

fraction& fraction::operator++(int)
{ 
    fraction res = *this;
    numerateur=numerateur+denominateur;
    return res;
}
void math::print(fraction const &a)
{
    std::cout << a.numerateur << "/" << a.denominateur;
}

void math::operator<<(std::ostream &flux, fraction const &a)
{
    print(a);
}