#pragma once

#include "clsDblLinkedList.h"

template<class T> class clsMyQueue {
protected:
    clsDblLinkedList<T> _MyList;

public:
    void push(T value) {
        _MyList.InsertAtEnd(value);
    }

    void Print() {
        _MyList.PrintList();
    }

    int Size() {
        return _MyList.Size();
    }

    T front() {
        return _MyList.GetItem(0);
    }

    T back() {
        return _MyList.GetItem(Size()-1);
    }

    void pop() {
        _MyList.DeleteLastNode();
    }
};