#ifndef AAL_BENCHMARK_H
#define AAL_BENCHMARK_H

#include <chrono>
#include <memory>
#include "Generator.h"
#include "Shelf.h"

enum SortType {
    PRIMITIVE, PATTERN, OPTIMAL
};

class Benchmark {
private:
    shared_ptr<Shelf> shelf_1;
    shared_ptr<Shelf> shelf_2;

public:
    Benchmark(int startFrom, int endIn, int step, int p);

    long countTime(shared_ptr<Shelf> shelfToSort, const SortType sortType);
};


#endif //AAL_BENCHMARK_H
