#include "worker.h"
#include "compute.h"
#include <iostream>
#include <future>
#include <chrono>
#include <syncstream>

using namespace std;
using namespace chrono;

void work_min_threads() {
    cout << "\n=== VARIANT 1: Minimum Threads (2 threads) ===" << endl;
    auto start = steady_clock::now();

    auto futureB2 = async(launch::async, []() {
        quick("A2");
        slow("B2");
        quick("C2");
        });

    slow("A1");
    quick("B1");
    quick("C1");

    futureB2.wait();
    quick("D");

    auto end = steady_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    osyncstream(cout) << "\nTime: " << duration / 1000.0 << " seconds" << endl;
    osyncstream(cout) << "Work is done!" << endl;
}

void work_min_time() {
    cout << "\n=== VARIANT 2: Minimum Time (4 threads) ===" << endl;
    auto start = steady_clock::now();

    auto futureB2 = async(launch::async, []() {
        quick("A2");
        slow("B2");
        });

    slow("A1");
    quick("B1");

    auto futureC1 = async(launch::async, []() {
        quick("C1");
        });

    auto futureC2 = async(launch::async, []() {
        quick("C2");
        });

    futureB2.wait();
    quick("D");

    futureC1.wait();
    futureC2.wait();

    auto end = steady_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();

    osyncstream(cout) << "\nTime: " << duration / 1000.0 << " seconds" << endl;
    osyncstream(cout) << "Work is done!" << endl;
}