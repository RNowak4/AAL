#include <iostream>
#include "../headers/Benchmark.h"

Benchmark::Benchmark(int startFrom, int endIn, int step, int p = 25) {
    for (int i = startFrom; i <= endIn; i += step) {
        auto genVector = (new Generator(i, p))->getInitVector();
        shelf_1.reset(new Shelf(genVector));
        shelf_2.reset(new Shelf(genVector));

        cout << "Sortowanie prymitywne dla: " << i << " wynioslo: " << countTime(shelf_1, PRIMITIVE) << "ms.";

        cout << endl;

        cout << "Sortowanie pattern-sort dla: " << i << " wynioslo: " << countTime(shelf_2, PATTERN) << "ms.";

        cout << endl;

        cout << endl;
    }
}

long Benchmark::countTime(shared_ptr<Shelf> shelfToSort, const SortType sortType) {
    long start, end;

    start = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();

    if (sortType == PRIMITIVE) {
        shelfToSort->sort();
    } else if (sortType == PATTERN) {
        shelfToSort->patternSort();
    } else {
        throw runtime_error("Not supported yet!");
    }

    end = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();

    return (end - start);
}
