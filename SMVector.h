#include <bits/stdc++.h>
using namespace std;

template <class T>
class SMVector {
private:
    int size, capacity;
    T*vector;
public:
    using iterator = T*;
    SMVector(int cap = 5);
    SMVector (T* , int n);
    SMVector (const SMVector&);
    ~SMVector();
    SMVector &operator = (const SMVector&);
    SMVector &operator = (const SMVector&&);
    T& operator[](int);
    int push_back(T);
    T pop_back();
    void erase(iterator);
    void erase(iterator, iterator);
    void clear();
    void insert(iterator, T);
    iterator begin();
    iterator end();
    bool operator == (const SMVector<T>&);
    bool operator < (const SMVector<T>&);
    int Size();
    int Capacity();
    int resize();
    bool empty();
    friend ostream& operator << (ostream& out, const SMVector <T>&);
};



