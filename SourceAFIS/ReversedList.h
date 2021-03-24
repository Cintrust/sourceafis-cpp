//
// Created by Junior Trust on 2/22/2020.
//

#ifndef SOURCEAFIS_CPP_REVERSEDLIST_H
#define SOURCEAFIS_CPP_REVERSEDLIST_H

#include <Utils/bridges/JavaList.h>

template<typename T>
class ReversedList : public JavaList<T> {
    JavaList<T> &inner;
public:
    explicit ReversedList(JavaList<T> &inner) : inner(inner) {
    }

    virtual bool add(const T &item) {
        inner.add(0, item);
        return true;
    }

    virtual void add(int index, const T &item) {
        inner.add(size() - index, item);
    }

    virtual int size() const {
        return inner.size();
    }

    virtual bool isEmpty() const {
        return inner.isEmpty();
    }

    virtual const T &get(int index) const {
        return inner.get(size() - index - 1);
    }
    virtual T &get(int index)  {
        return inner.get(size() - index - 1);
    }

    virtual T remove(int index) {
        return inner.remove(size() - index - 1);
    }



    virtual ~ ReversedList() = default;
};


#endif //SOURCEAFIS_CPP_REVERSEDLIST_H
