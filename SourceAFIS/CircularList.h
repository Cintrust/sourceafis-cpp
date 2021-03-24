//
// Created by Junior Trust on 2/22/2020.
//

#ifndef SOURCEAFIS_CPP_CIRCULARLIST_H
#define SOURCEAFIS_CPP_CIRCULARLIST_H


#include "Utils/bridges/JavaList.h"
#include "CircularArray.h"

template <class T = IntPoint>
class CircularList : public JavaList<T> {
 CircularArray<T> inner;

public:
    CircularList():inner(){

    }
 virtual bool add( const T &item) {
        inner.insert(inner.size(), item);
        return true;
    }

    virtual void add(int index, const T &item) {
        inner.insert(index, item);
    }
    virtual  int size() const {
        return  inner.size();
    }

    virtual  bool isEmpty() const {
        return  size() == 0;
    }

    virtual  const T & get(int index) const {
        return inner.get(index);
    }
    virtual   T & get(int index)  {
        return inner.get(index);
    }
    virtual T  remove(int index) {
        T result = get(index);
        inner.remove(index, 1);
        return result;
    }

    ~CircularList()= default;
};


#endif //SOURCEAFIS_CPP_CIRCULARLIST_H
