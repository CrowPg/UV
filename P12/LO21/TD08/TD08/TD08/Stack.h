//
//  Stack.h
//  TD08
//
//  Created by Johan Medioni on 11/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD08_Stack_h
#define TD08_Stack_h
#include "Vector.h"

template <class T>
class Stack: private Vector<T>{//on expose les nouvelles méthodes
public:
    Stack(): Vector<T>(0){}
    bool empty() const{return Contener<T>::empty();}
    void push(const T& x){Contener<T>::push_back(x);}
    void pop(){Contener<T>::pop_back();}
    unsigned int size() const {return Contener<T>::size();}
    T& top() {return Contener<T>::back();}
    const T& top() const {return Contener<T>::back();}
    void clear(){Contener<T>::clear();}
    class Iterator:public Vector<T>::Iterator{
        Iterator(typename Vector<T>::Iterator it) : Vector<T>::Iterator(it){}
    };
    class const_Iterator:public Vector<T>::const_Iterator{
        const_Iterator(typename Vector<T>::const_Iterator it):Vector<T>::const_Iterator(it){}
    };
    const_Iterator begin() const{return const_Iterator(Vector<T>::begin());}
    const_Iterator end() const{return Vector<T>::end();}
};

template <class IT>
IT element_minimum(IT it1, IT it2);

template <class IT, class COMP>
IT element_minimum(IT it1, IT it2, COMP comp);

template <class IT>
IT element_minimum(IT it1, IT it2){
    IT it_min = it1;
    ++it1;
    while(it1!= it2){
        if (*it1 < *it_min)
            it_min=it1;
        ++it1;
    }
    return it_min;
}

bool sup(int a, int b);
bool sup(int a, int b){
    return a>b;
}

class Comparateur{
public:
    enum ordre{croissant, decroissant};
private:
    ordre d;
public:
    Comparateur(ordre o = croissant):d(o){}
    bool operator()(int a, int b){
        if (d==decroissant)
            return a<b;
        else
            return a>b;
    }
};

#endif
