//
//  film.cpp
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "film.h"

std::ostream& operator<<(std::ostream& os, const Cinema::Film f)
{
    os << f.Afficher(os);
    return os;
}