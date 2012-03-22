//
//  header.h
//  Exercice 10
//
//  Created by Johan Medioni on 18/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Exercice_10_header_h
#define Exercice_10_header_h

struct Date
{
    unsigned int jour, mois, annee;
    Date ModifDateVal(Date d, unsigned int j, unsigned int m, unsigned int a);
    void ModifDateAdr(Date *d, unsigned int j, unsigned int m, unsigned int a);
    void ModifDateRef(Date &d, unsigned int j, unsigned int m, unsigned int a);
    
};

#endif
