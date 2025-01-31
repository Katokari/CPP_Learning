#pragma once

#include "clsMyStack.h"

using namespace std;

template <class T> class clsDynamicArray {
protected:
    int _Size = 0;
    T* _TempArray;

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

    void Resize(int NewSize)
    { 
        if (NewSize < 0)
            NewSize = 0;

        _TempArray = new T[NewSize];

        if (NewSize < _Size)
            _Size = NewSize;

        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = Array[i];
        }

        _Size = NewSize;

        delete[] Array;
        Array = _TempArray;
    }

    T GetItem(int Index) {
        return Array[Index];
    }

    void Reverse() {
        _TempArray = new T[_Size];
        for (int i = 0; i < _Size; i++)
            _TempArray[_Size-i-1] = Array[i];
        
        delete[] Array;
        Array = _TempArray;
    }

    void Clear() {
        _Size = 0;
        _TempArray = new T[0];
        delete[] Array;
        Array = _TempArray;
    }

    void DeleteItemAt(int Index) {
        if (_Size == 0) return;

        if (Index < 0 || Index >= _Size)
            return;

        _TempArray = new T[_Size-1];
        for (int i = 0; i < Index; i++)
        {
            _TempArray[i] = Array[i];
        }

        for (int i = Index+1; i < _Size; i++) {
            _TempArray[i-1] = Array[i];
        }

        _Size = _Size -1;

        delete[] Array;
        Array = _TempArray;
    }

    void DeleteFirstItem() {
        DeleteItemAt(0);
    }

    void DeleteLastItem() {
        DeleteItemAt(_Size-1);
    }
};