//
//  Contener.h
//  TD08
//
//  Created by Johan Medioni on 11/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD08_Contener_h
#define TD08_Contener_h

class contener_exception : public std::exception{
    std::string info;
public:
    contener_exception(const std::string& i="")throw() : info(i){}
    ~contener_exception()throw(){}
    const char* what() const throw(){return info.c_str();}
};

template <class T>
class Contener{
protected:
    unsigned int fSize;
public:
    Contener(unsigned int s=0):fSize(s){}
    virtual ~Contener(){}
    unsigned int size() const {return fSize;}
    bool emplty() const {if (fSize!=0) return false; return true;}
    virtual T& element(unsigned int i)=0;
    virtual const T& element(unsigned int i) const=0;
    T& back(){
        if (fSize==0) 
            throw contener_exception("\nImpossible de retirer un objet d'un contener vide.");
        return element(fSize-1);
    }
    const T& back() const{
        if (fSize==0) 
            throw contener_exception("\nImpossible de retirer un objet d'un contener vide.");
        return element(fSize-1);
    }
    virtual void push_back(const T& x)=0;
    virtual void pop_back()=0;
    void clear(){
        while (fSize!=0)
            pop_back();
    }
};


#endif
