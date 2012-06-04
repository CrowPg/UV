//
//  Constante.h
//  Nombres
//
//  Created by Johan Medioni on 04/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Nombres_Constante_h
#define Nombres_Constante_h
#include <exception>
#include <iostream>

class Constante{
public:
    virtual void afficher()=0;
};

class Erreur : public std::exception{
    int m_num; //numéro de l'erreur
    std::string desc; //description de l'erreur
    
public:
    Erreur(int numero=0, std::string const& phrase="", int niveau=0) throw() : m_num(numero),desc(phrase){}
    
    std::string getDesc(){
        return desc;
    }
    
    virtual ~Erreur() throw(){}
    
    void afficher() const{
        std::cout << "\n Erreur de type " << m_num << " : " << desc << std::endl;
    }
};


#endif
