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

template <class T>
T& SMVector<T>:: operator[](int index){
    try {
        if (index > size - 1) {
            throw exception();
        }
        return vector[index];
    }
    catch(exception e){
        cout << "ERROR! This is out of range.\n";
        }
}


template <class T>
int SMVector<T>::push_back(T item) {
    if (size < capacity){
        vector[size++] = item;
    }
    else {
        cout << "Resize to " << capacity*2 << endl;
        T* newvector = new T[capacity*2];
        capacity *= 2;

        for(size_t i = 0; i < size; i++){
            newvector[i] = vector[i];
        }
        delete[] vector;
        vector = newvector;
        newvector = nullptr;
        vector[size++] = item;
    }
    return size+1;
}

template <class T>
T SMVector<T>::pop_back() {
    return vector[size-- -1];
}

template <class T>
void SMVector<T>::erase(iterator it) {
    auto index = -1;
    try {
        for(size_t i =0; i < size; i++) {
            if (&vector[i] == it) {
                index = i;
                break;
            }
        }
        if ( index== -1)  {
            throw exception();
        }

        for(auto i = index; i < Size()-1; i++){
            vector[i] = vector[i+1];
        }
        --size;
    }
    catch (exception e) {
        cout<<"ERROR! This is out of range."<<endl;
    }
}

template <class T>
void SMVector<T>:: erase(iterator it1, iterator it2) {
    try {

        auto index1 = -1, index2 = -1;

        for (size_t i = 0; i < size; i++) {
            if (&vector[i] == it1) {
                index1 = i;
                break;
            }
        }
        for (size_t i = 0; i < size; i++) {
            if (&vector[i] == it2) {
                index2 = i;
                break;
            }
        }
        if (index1 == -1 || index2 == -1) {
            throw exception();
        }
        for (auto i = index1; i <= index2; i++) {
            erase(it1);
            index1++;
        }

    }
    catch (exception e){
        cout<<"ERROR! This is out of range."<<endl;
    }
}

template <class T>
void SMVector<T>::clear(){
    int Size = size;
    for(size_t i = 0 ; i < Size ; i++){
        pop_back();
    }
}

template <class T>
void SMVector<T>::insert(iterator it , T item) {
    try {
        if (it != end()) {
            if (it > end() || it < begin()) {
                throw 0;
            }
            bool flag = false;
            T *newvector = new T[size];

            for (size_t i = 0; i < size; i++) {
                if (&vector[i] == it) {
                    newvector[i] = item;
                    size++;
                    flag = true;
                } else if (flag == false) {
                    newvector[i] = vector[i];
                } else if (flag == true) {
                    newvector[i] = vector[i - 1];
                }
            }
            delete[] vector;
            vector = newvector;
        }
        else if(it == end()){
            push_back(item);
        }

    }
    catch (int e){
        cout << "ERROR! This out of range." << endl;
    }

}


