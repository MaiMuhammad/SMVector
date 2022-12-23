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

template <class T>
SMVector<T> ::SMVector(int cap) {
    capacity = cap;
    size = 0;
    vector = new T[capacity];
}

template <class T>
SMVector<T>::SMVector(T* array , int n) {
    size = n;
    vector = new T[size];
    for(size_t i=0; i<size ; i++){
        vector[i]=array[i];
    }
}

template <class T>
SMVector<T>::SMVector (const SMVector& vec){
    size=vec.size;
    capacity=vec.capacity;
    vector=new T[capacity];
    for(size_t i=0; i<vec.size; i++){
        vector[i]=vec.vector[i];
    }
}

template <class T>
SMVector<T>::~SMVector(){
    delete[]vector;
}

//copy assignment
template <class T>
SMVector<T> & SMVector<T> :: operator = (const SMVector& vec) {
    if(this!= &vec){
        delete [] vector;
        size = vec.size;
        capacity = vec.capacity;
        vector = new T[capacity];
        for(size_t i=0; i< vec.size; i++){
            vector[i]=vec.vector[i];
        }
        return *this;
    }
    else{
        cout << "Cannot delete self." << endl;
    }
}

//Move assignment
template <class T>
SMVector<T> & SMVector<T> :: operator = (const SMVector&& vec) {
    this->size=size;
    this->capacity=capacity;
    this->vector=vector;
    vec.size=0;
    vec.capacity=0;
    vec.vector= nullptr;
    return *this;
}


