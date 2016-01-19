#ifndef AAL_BENCHMARK_H
#define AAL_BENCHMARK_H

#include <chrono>
#include <memory>
#include "Generator.h"
#include "Shelf.h"

enum SortType {
    PRIMITIVE, PATTERN, FAST
};

enum {
    DEFAULT_PRECISION = 1
};

class Benchmark {
private:
    int precision;
    shared_ptr<Shelf> shelf_1;
    shared_ptr<Shelf> shelf_2;
    shared_ptr<Shelf> shelf_3;
    vector<shared_ptr<long> > resultsVector;

    void runBenchmark(const vector<int> &inputVector);

public:
    Benchmark();

    static long countTime(shared_ptr<Shelf> shelfToSort, const SortType sortType);

    void runUser();

    void runRandom(int startFrom, int endIn, int step);

    const vector<shared_ptr<long>> &getResultsVector() const {
        return resultsVector;
    }

    const vector<int> readInputVector();


    void setPrecision(int precision) {
        Benchmark::precision = precision;
    }
};


#endif //AAL_BENCHMARK_H
