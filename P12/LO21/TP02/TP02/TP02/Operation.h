//
//  Operation.h
//  TP02
//
//  Created by Johan Medioni on 26/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TP02_Operation_h
#define TP02_Operation_h

namespace banque
{
    class Operation
    {
    public:
        std::string nom;
        float taux;
        double soldeMin, soldeMax;
        
        void Afficher();
        
        friend class Banque;
    };
}

#endif
