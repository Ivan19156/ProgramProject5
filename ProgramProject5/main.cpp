#include "worker.h"
#include <iostream>
#include <thread>

using namespace std;

int main() {
    cout << "Lab 2: Parallel Computing - Variant #25" << endl;
    cout << "Computations: A1, A2, B1, B2, C1, C2, D" << endl;
    cout << "Slow (7s): A1, B2" << endl;
    cout << "Dependencies: B1(A1), B2(A2), C1(A1), C2(A2), D(B1,B2)" << endl;

    work_min_threads();

    this_thread::sleep_for(chrono::seconds(2));

    work_min_time();

    cout << "\n=== COMPARISON ===" << endl;
    cout << "Variant 1: 2 threads, ~10 seconds" << endl;
    cout << "Variant 2: 4 threads, ~9 seconds" << endl;

    return 0;
}