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
        _MyList.DeleteFirstNode();
    }

    T GetItem(int Index) {
        return _MyList.GetItem(Index);
    }

    void Reverse() {
        _MyList.Reverse();
    }

    void UpdateItem(int Index, T NewValue) {
        _MyList.UpdateItem(Index, NewValue);
    }

    void InsertAfter(int Index, T value) {
        _MyList.InsertAfter(Index, value);
    }

    void InsertAtFront(T value) {
        _MyList.InsertAtBeginning(value);
    }

    void InsertAtBack(T value) {
        _MyList.InsertAtEnd(value);
    }

    void Clear() {
        _MyList.Clear();
    }
};