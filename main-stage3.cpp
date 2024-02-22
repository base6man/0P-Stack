/*
 * main-stage3.cpp
 *
 * Includes the main() function for the stack project (stages 2 & 3).
 *
 * This code is included in the build target "run-stage3-main", and
 * in the convenience targets "stage2", and "stage3".
 */

#include <iostream>

#include "stack-stage3.h"
#include "chrono"

using namespace std;

double time_n_pushes(unsigned n) {
    stack<unsigned> s;
    // get starting clock value
    auto start_time = chrono::system_clock::now();
    // do the n pushes
    for (unsigned i = 0; i < n; i++) {
    s.push(i);
    }
    // get ending clock value
    auto stop_time = chrono::system_clock::now();
    // compute elapsed time in seconds
    chrono::duration<double> elapsed = stop_time - start_time;
    return elapsed.count();
}

int main() {
    // You can use this main() to run your own analysis or initial testing code.
    for(unsigned i = 1; i <= 10; i++){
        unsigned long long bigI = i * 1000000;
        cout << time_n_pushes(bigI) << endl;
    }
    return 0;
}
