#ifndef AAL_BENCHMARK_H
#define AAL_BENCHMARK_H

#include <chrono>
#include <memory>
#include "Generator.h"
#include "Shelf.h"

enum SortType {
    PRIMITIVE, PATTERN, FAST
};

class Benchmark {
private:
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
};


#endif //AAL_BENCHMARK_H
