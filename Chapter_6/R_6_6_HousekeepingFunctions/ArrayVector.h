#ifndef _ARRAYVECTOR_H_
#define _ARRAYVECTOR_H_


#include <iostream>

template<typename T>
class ArrayVector;

template<typename T>
std::ostream& operator<< (std::ostream& os, const ArrayVector<T>& obj) {
    os << "Capacity:" << obj.capacity << " Size:" << obj.n << " Array content: ";
    for(int i = 0; i < obj.n; i++) {
        os << obj.A[i] << " ";
    }
    std::cout << std::endl;
    return os;
}


template<typename T>

class ArrayVector
{
    friend std::ostream& operator<< <>(std::ostream& os, const ArrayVector<T>& obj);
public:
    ArrayVector();
    ArrayVector(const ArrayVector& source);
    ~ArrayVector();
    
    
    int size() const;
    bool empty() const;
    T& operator[](int i);
    T& at(int i);
    ArrayVector& operator=(const ArrayVector& rhs);
    
    
    void erase(int i);
    void insert(int i, const T& e);
    void reserve(int N);
    
private:
    int capacity;
    int n;
    T* A;

};

  
    
    template<typename T>
    ArrayVector<T>::ArrayVector()
        :capacity(0), n(0), A(nullptr) {}
    
    
    template<typename T>
    ArrayVector<T>::ArrayVector(const ArrayVector& source) 
        : ArrayVector() {
          for(int i = 0; i < source.n; i++) {
              this->insert(i,source.A[i]);
          }  
        }
        
    
        
    
    template<typename T>
    int ArrayVector<T>::size() const {return n;}
    
    
    template<typename T>
    bool ArrayVector<T>::empty() const {return size() == 0;}
    
    
    template<typename T>
    T& ArrayVector<T>::operator[](int i) {return A[i];}
    
    
    template<typename T>
    T& ArrayVector<T>::at(int i) {
        if (i < 0 || i >= n) throw ("illigal index in function at()");
        return A[i];
    }
    
    
    template<typename T>
    ArrayVector<T>::~ArrayVector() {
        delete [] A;
        std::cout << "~Destructor" << std::endl;
    }
    
    template<typename T>
    void ArrayVector<T>::reserve(int N) {
        if (capacity >= N) return;
        T* B = new T[N];
        for (int j = 0; j < n; j++)
            B[j] = A[j];
        if (A != nullptr) delete[] A;
        A = B;
        capacity = N;
    }
    
    
    template<typename T>
    void ArrayVector<T>::insert(int i, const T& e) {
        try {
        if(i <= capacity) {
            if (n >= capacity)
                reserve(std::max(1, 2 * capacity));
            for (int j = n - 1; j >= i; j--)
                A[j+1] = A[j];
            A[i] = e;
            n++;
            }
        else throw ("Index out of Bounds");
        }
        catch (const char* ex) {
            std::cerr << "Error: " << ex << std::endl;
        }
    }
    
    
    
    template<typename T>
    ArrayVector<T>& ArrayVector<T>::operator=(const ArrayVector<T>& rhs) {
        if(this == &rhs)
            return *this;
        delete[] A;
        this->A = new T[rhs.capacity];
        for(int i = 0; i < rhs.n; i++) {
            A[i] = rhs.A[i];
        }
        capacity = rhs.capacity;
        n = rhs.n;
        return *this;
    }


#endif // _ARRAYVECTOR_H_
