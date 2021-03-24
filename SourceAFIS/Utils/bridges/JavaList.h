//
// Created by Junior Trust on 2/22/2020.
//

#ifndef SOURCEAFIS_CPP_JAVALIST_H
#define SOURCEAFIS_CPP_JAVALIST_H

#include <iterator>

template<class T>
class JavaList {

public:

    virtual bool add(const T &o) = 0;

    virtual void add(int index, const T &item) = 0;

    virtual int size() const = 0;

    virtual bool isEmpty() const = 0;

    virtual const T &get(int index) const = 0;
    virtual  T &get(int index)  = 0;

    virtual int indexOf(const T & o) const {
        for (int i = 0; i < size(); ++i)
            if (get(i) == o)
                return i;
        return -1;
    }
    bool contains(const T & o) {
        return indexOf(o) >= 0;
    }



//    virtual bool remove(const T &o) = 0;
    bool remove(const T & o) {
        int index = indexOf(o);
        if (index >= 0) {
            remove(index);
            return true;
        } else
            return false;
    }

    virtual T remove(int index) = 0;

    virtual  ~JavaList() = default;


    template <class  Object>
    class JL_Iterator {

         Object * const javaList_ptr;
        int index;

        bool hasNext() {
            return index < javaList_ptr->size();
        }

    public:
        typedef JL_Iterator self_type;
        typedef T value_type;
        typedef T &reference;
        typedef T *pointer;
        typedef std::input_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;

        JL_Iterator(int index,Object * const parent) : javaList_ptr(parent), index(index) {}

        self_type &operator++() {

            ++index;

            if (!hasNext()) {
                index = javaList_ptr->size();
            }

            return *this;
        }

        self_type operator++(int) {
            self_type val = *this;
            ++(*this);
            return val;
        }

        inline bool operator==(const self_type &other) const {
            return (this == &other) || (other.javaList_ptr == javaList_ptr && index == other.index);
        }

        inline bool operator!=(const self_type &other) const { return !(*this == other); }

        reference operator*() const { return (javaList_ptr->get(index)); }

        pointer operator->() const { return &(javaList_ptr->get(index)); }

    };

    typedef JL_Iterator<const JavaList<T>> const_iterator;
    typedef JL_Iterator <JavaList<T>> iterator;

    iterator begin() { return iterator(0, this); }

    iterator end() { return iterator(this->size(), this); }

    const_iterator begin() const { return const_iterator(0, this); }

    const_iterator end() const { return const_iterator(this->size(), this); }

    const_iterator cbegin() { return const_iterator(0, this); }

    const_iterator cend() { return const_iterator(this->size(), this); }

};


#endif //SOURCEAFIS_CPP_JAVALIST_H
