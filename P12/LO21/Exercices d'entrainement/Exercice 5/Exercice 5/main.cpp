//
//  main.cpp
//  Exercice 5
//
//  Created by Johan Medioni on 18/03/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;

int main (int argc, const char * argv[])
{
    double x=3.14;
    cout << x;
    double *pt=&x;
    double &ref=x;
    
    cout << "\nAdresse de x : " << &ref;
    cout << "\nValeur de x : " << ref;
    ref=3.14159;
    cout << "\n";
    cout << "\nAdresse de x : " << &ref;
    cout << "\nNouvelle valeur de x : " << ref;
    cout << "\n";
    cout << "\n";
    
    cout << "\nAdresse de x : " << pt;
    cout << "\nAdresse du pointeur sur x : " << &pt;
    cout << "\nValeur de x : " << *pt;
    *pt=3.14159265;
    cout << "\n";
    cout << "\nAdresse de x : " << pt;
    cout << "\nNouvelle valeur de x : " << *pt;
    cout << "\n";
    cout << "\n";
    
     
    return 0;
}