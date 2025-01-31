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
        delete[] Array; // Free existing memory
        _Size = 0;
        Array = new T[0]; // Assign valid empty array
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

    int Find(T value) {
        for (int i = 0; i < _Size; i++) {
            if (Array[i] == value)
                return i;
        }
        return -1;
    }

    bool DeleteItem(T value) {
        int Index = Find(value);
        if (Index == -1) return false;
        DeleteItemAt(Index);
        return true;
    }

    void InsertAt(int Index, T value) {
        if (Index < 0 || Index > _Size) return;
        int OriginalSize = _Size;
        _Size++;
        T* TempArray = new T[_Size];
        for (int i = 0; i < Index; i++) {
            TempArray[i] = Array[i];
        }
        TempArray[Index] = value;
        
        for (int i = Index; i < OriginalSize; i++) {
            TempArray[i + 1] = Array[i];
        }
        delete[] Array;
        Array = TempArray;
    }

    void InsertAtBeginning(T value) {
        InsertAt(0, value);
    }

    void InsertBefore(int Index, T value) {
        if (Index < 1)
            InsertAt(0, value);
        else
            InsertAt(Index-1, value);
    }

    void InsertAfter(int Index, T value) {
        if (Index < 0 || Index >= _Size) {
            InsertAtEnd(value);
        } else {
            InsertAt(Index + 1, value);
        }
    }

    void InsertAtEnd(T value) {
        InsertAt(_Size, value);
    }
};  