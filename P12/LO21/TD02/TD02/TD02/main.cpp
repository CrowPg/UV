//
//  main.cpp
//  TD02
//
//  Created by Johan Medioni on 19/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "fractions.h"
using namespace math;
using namespace std;

int main (int argc, const char * argv[])
{

    fraction f(2,4);
    print(f);
    cout << "\n" << f++;
    return 0;
}

