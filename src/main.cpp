#include <chrono>
#include <iostream>
#include "headers/Benchmark.h"

using namespace std;

int main() {
    srand((unsigned int) time(NULL));

    new Benchmark(1000, 10000, 1000, 60);

    return 0;
}