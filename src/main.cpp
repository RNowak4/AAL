#include <chrono>
#include <iostream>
#include "headers/Benchmark.h"

using namespace std;

int main() {
    srand((unsigned int) time(NULL));

    Benchmark *benchmark = new Benchmark(3000, 3000, 1000, 60);

    delete benchmark;

    return 0;
}