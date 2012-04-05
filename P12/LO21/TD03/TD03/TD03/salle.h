//
//  salle.h
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD03_salle_h
#define TD03_salle_h

class Salle
{
    Static unsigned int idGen;
    unsigned int num;
    Planning planning;
    
public:
    Salle(const Planning&p) : num(idgen++), planning(p){}
    ~Salle(){}
    void Afficher(std::ostream& os=cout) const
    {
        os << "Salle "<< num << endl << endl << planning;
    }
}

#endif
