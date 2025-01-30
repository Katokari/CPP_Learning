#pragma once

#include "clsMyStack.h"

using namespace std;

template <class T> class clsDynamicArray {
protected:
    int _Size = 0;

public:
    T* Array;
    clsDynamicArray(int Size = 0) {
        if (Size < 0)
            Size = 0;
        _Size = Size;
        Array = new T[_Size];
    }

    ~clsDynamicArray() {
        delete[] Array;
    }

    bool SetItem(int Index, T value) {
        if(Index > _Size && Index < 0)
            return false;
        *(Array+Index) = value;
        return true;
    }

    bool IsEmpty() {
        return _Size == 0;
    }

    int Size() {
        return _Size;
    }

    void PrintList() {
        for (int i = 0; i < _Size; i++) {
            cout << Array[i] << " ";
        }
    }
};