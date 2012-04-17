//
//  Header.h
//  TD04
//
//  Created by Johan Medioni on 16/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD04_Header_h
#define TD04_Header_h
#include "time.h"
using namespace std;

namespace TIME
{
    class Ev_1j
    {
    protected:
        string _objet;
        Date _date;
    public:
        Ev_1j(int j, int m, int a, const string& obj): _objet(obj), _date(j,m,a){}
        const string& get_description() const 
        { 
            return _objet; 
        } 
        const Date& get_date() const 
        { 
            return _date; 
        }
        virtual void afficher(ostream& f= cout) const;
       
        
    };
}
ostream& operator<<(ostream& os, const TIME::Ev_1j& evt);


#endif
