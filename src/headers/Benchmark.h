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
    DEFAULT_PRECISION = 1,
    DEFAULT_TABLE_WIDTH = 15
};

class Benchmark {
private:
    int precision;
    shared_ptr<Shelf> shelf_1;
    shared_ptr<Shelf> shelf_2;
    shared_ptr<Shelf> shelf_3;
    vector<shared_ptr<long> > resultsVector;

    void runBenchmark(const vector<int> &inputVector);

    void showAlgorithmInfo(const string &algorithmInfo, int complexity, const vector<shared_ptr<long> > &resultVector,
                           int start, int end) const;

public:
    Benchmark();

    static long countTime(shared_ptr<Shelf> shelfToSort, const SortType sortType);

    void runUser();

    void runRandom(int startFrom, int endIn, int step);

    const vector<shared_ptr<long>> &getResultsVector() const {
        return resultsVector;
    }

    const vector<int> readInputVector();

    void printResults() const;

    void setPrecision(int precision) {
        Benchmark::precision = precision;
    }

    void stepByStep(const int size, const int p, const SortType) const;
};


#endif //AAL_BENCHMARK_H
