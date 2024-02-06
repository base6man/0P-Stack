/*
 * stack-stage1.h
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

using namespace std;

class stack {
  public:
    string top() {
      return _data[data_size-1];
    }

    // inline definitions, doing nothing at the moment
    void push(const string &new_string) { 

      if(data_size == stack_size){
        stack_size *= 2;
        
        string *new_data = new string[stack_size];
        for(size_t i = 0; i < data_size; i++){
          new_data[i] = _data[i];
        }

        delete[] _data;
        _data = new_data;
      }
      _data[data_size] = new_string;
      data_size++;
    }

    void pop() { 
      data_size--;
      _data[data_size] = "";
    }

    size_t size() { 
      return data_size;
    }

    bool is_empty() { return data_size == 0; }

    stack() { 
      data_size = 0;
      _data = new string[stack_size];
    }

  private:
    string *_data;
    size_t data_size;
    size_t stack_size = 32;
};

#endif
