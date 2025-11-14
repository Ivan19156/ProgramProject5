#include "compute.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <syncstream>

void compute(const std::string& name, int duration) {
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    std::osyncstream(std::cout) << name << std::endl;
}

void slow(const std::string& name) {
    compute(name, 7);
}

void quick(const std::string& name) {
    compute(name, 1);
}