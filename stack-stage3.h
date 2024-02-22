/*
 * stack-stage3.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Your Name
 */

#ifndef _STACK_H
#define _STACK_H

#include <cstddef> // for size_t
#include <string>  // for stage 1
#include <iostream>

using namespace std;

template <typename T>
class stack {
  public:
    // template <typename T>
    T top() {
        return _data[data_size-1];
    }

    // template <typename T>
    void push(const T &new_t) { 

        if(data_size == stack_size){
            stack_size = stack_size * 1.5 + 1;
            
            T *new_data = new T[stack_size];
            for(size_t i = 0; i < data_size; i++){
                new_data[i] = _data[i];
            }

        delete[] _data;
        _data = new_data;
        }
        _data[data_size] = new_t;
        data_size++;
    }

    void pop() { 
        data_size--;
    }

    size_t size() { 
        return data_size;
    }

    bool is_empty() { return data_size == 0; }

    // template <typename T>
    stack() { 
        data_size = 0;
        _data = new T[stack_size];
    }

    ~stack(){
        delete[] _data;
    }

    stack(const stack &other){
        data_size  = other.data_size;
        stack_size = other.stack_size;
        _data = new T[stack_size];
        for(size_t i = 0; i < data_size; i++){
            _data[i] = other._data[i];
        }
    }

    stack operator=(const stack &other){
        if(&other == this) return *this;
        delete[] _data;

        data_size  = other.data_size;
        stack_size = other.stack_size;
        _data = new T[stack_size];
        for(size_t i = 0; i < data_size; i++){
            _data[i] = other._data[i];
        }

        return *this;
    }

private:
    T *_data;
    size_t data_size;
    size_t stack_size = 1;
};

#endif
