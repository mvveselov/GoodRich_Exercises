#ifndef _STACK_VECTOR_H_
#define _STACK_VECTOR_H_

#include <vector>
#include "StackEmpty.h"





template <typename T>
class Stack_Vector
{
public:
    int size() const;
    bool empty () const;
    const T& top() const {
            if(vec.empty()){
                throw StackEmpty{"Cannot perform top() method, Stack is empty"};
            }
            else return vec.back();
    }
    void push (const T& e) {
        vec.push_back(e);
    }
    void pop () {
        if(vec.empty()){
           throw StackEmpty{"Cannot perform pop() method, Stack is empty"};
        }
    else vec.pop_back();
    }

    Stack_Vector() = default;
    ~Stack_Vector() = default;
    
private:
    std::vector<T> vec;

};

    template <typename T>
    bool Stack_Vector<T>::empty () const {
        return vec.empty();
    }

    template <typename T>
    int Stack_Vector<T>::size() const {
        return vec.size();
    }


#endif // _STACK_VECTOR_H_
