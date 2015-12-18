#include <chrono>
#include <iostream>
#include "headers/Benchmark.h"

using namespace std;

int main() {
    srand((unsigned int) time(NULL));

    new Benchmark(5000, 5000, 1000, 25);

    return 0;
}