//
//  header.h
//  TD02
//
//  Created by Johan Medioni on 19/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD02_header_h
#define TD02_header_h

namespace math 
{
    struct fraction
    {
        int numerateur;
        int denominateur;
        
        int get_num() const ;
        int get_den() const;
        
        void set_num(int n);
        void set_den(int d);
        
        fraction(int n=0, int d=1);
        ~fraction();
        
        fraction somme(const fraction &frac) const;
        
        fraction& operator++();
        fraction& operator++(int);
        
        
    private:
        void simplify();
        
        friend fraction operator+(fraction const &a, fraction const &b);
        friend fraction operator-(fraction const &a, fraction const &b);
        friend fraction operator*(fraction const &a, fraction const &b);
        friend fraction operator/(fraction const &a, fraction const &b);
    };
    
    fraction operator+(fraction const &a, fraction const &b);
    fraction operator-(fraction const &a, fraction const &b);
    fraction operator*(fraction const &a, fraction const &b);
    fraction operator/(fraction const &a, fraction const &b);
    
    void operator<<(std::ostream &flux,fraction const &a);
    
    void print(fraction const &a);
};



#endif
