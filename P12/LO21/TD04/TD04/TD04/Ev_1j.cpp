//
//  Ev_1j.cpp
//  TD04
//
//  Created by Johan Medioni on 16/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Ev_1j.h"
using namespace std;

ostream& operator<<(ostream& os, const TIME::Ev_1j& evt)
{
    evt.afficher(os);
    return os;
}

void TIME::Ev_1j::afficher(ostream& f) const
{
    f<<"***** evt ********"<<"\n";
    f<<"Date="<<this->_date<<" objet="<<this->_objet<<"\n";
}
