//
//  Vector.h
//  TD08
//
//  Created by Johan Medioni on 11/06/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD08_Vector_h
#define TD08_Vector_h
#include "Contener.h"

template <class T>
class Vector: public Contener<T>{
protected:
    T* table;
public:
    Vector(const T& defaultValue, unsigned int size=0):Contener<T>(size), table(new T[size]){
        for (unsigned int i=0 ; i<Contener<T>::fSize ; i++)
            table[i]=defaultValue;
    }
    ~Vector(){
        delete[] table;
    }
    Vector(const Vector<T>& v);
    Vector<T>& operator=(const Vector<T>& v);
    T& element(unsigned int i){
        if (Contener<T>::fSize<=i)
            throw contener_exception("Ah ah ah");
        return table[i];
    }
    void push_back(const T& x);
    void pop_back();
    T& operator[](unsigned int i){return element (i);}
    const T& operator[](unsigned int i) const {return element(i);}
    
    class Iterator{
        T* element;
    public:
        Iterator(T* e = 0):element(e){}
        Iterator& operator++(){element++; return *this;}
        Iterator operator++(int){Iterator returnIt=*this; element++; return returnIt;}
        bool operator==(const Iterator& i) const{return i.element==element;}
        bool operator!=(const Iterator& i) const{return i.element!=element;}
        T& operator*(){return *element;}
        void swap(Iterator& i){T tmp = *element; *element = *i.element; *i.element=tmp;}
    };
    class const_Iterator{
        const T* element;
    public:
        const_Iterator(T* e = 0):element(e){}
        const_Iterator& operator++(){element++; return *this;}
        const_Iterator operator++(int){const_Iterator returnIt=*this; element++; return returnIt;}
        bool operator==(const const_Iterator& i) const{return i.element==element;}
        bool operator!=(const const_Iterator& i) const{return i.element!=element;}
        const T& operator*(){return *element;}
    };
    const_Iterator begin(){return const_Iterator(table);}
    const_Iterator end(){return const_Iterator(table+Contener<T>::fSize);}
};

template <class T>
Vector<T>::Vector(const Vector<T>& vector):Contener<T>(vector.size()), table(new T[Contener<T>::fSize]){
    for(unsigned int i=0 ; i<vector.size() ; i++)
        table[vector.element(i)];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vector){
    delete[] table;
    table = new T[vector.size()];
    Contener<T>::fSize=vector.size();
    for (unsigned int i=0 ; i < vector.size() ; i++)
        table[i]=vector.element(i);
}

template <class T>
void Vector<T>::push_back(const T& x){
    T* tmp = new T[Contener<T>::fSize+1];
    for (unsigned int i=0 ; i<Contener<T>::fSize ; i++)
        tmp[i] = table[i];
    tmp[Contener<T>::fSize++] = x;
    delete[] table;
    table = tmp;
}

template <class T>
void Vector<T>::pop_back(){
    T* tmp = new T[Contener<T>::fSize-1];
    for (unsigned int i=0 ; i<Contener<T>::fSize-1 ; i++)
        tmp[i] = table[i];
    delete[] table;
    table = tmp;
}


#endif
