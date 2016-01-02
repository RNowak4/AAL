#include <iostream>
#include <thread>
#include "../headers/Benchmark.h"

Benchmark::Benchmark(int startFrom, int endIn, int step, int p = 25) {
    shared_ptr<thread> t1, t2, t3;

    for (int i = startFrom; i <= endIn; i += step) {
        auto genVector = (new Generator(i, p))->getInitVector();
        shelf_1.reset(new Shelf(genVector));
        shelf_2.reset(new Shelf(genVector));
        shelf_3.reset(new Shelf(genVector));

        t1.reset(new thread(doSort, &shelf_1, i, PRIMITIVE));
        t2.reset(new thread(doSort, &shelf_2, i, PATTERN));
        t3.reset(new thread(doSort, &shelf_3, i, FAST));

        t1->join();
        t2->join();
        t3->join();

//        cout << "Sortowanie prymitywne dla: " << i << " wynioslo: " << countTime(shelf_1, PRIMITIVE) << "ms.";
//
//        cout << endl;
//
//        cout << "Sortowanie pattern-sort dla: " << i << " wynioslo: " << countTime(shelf_2, PATTERN) << "ms.";
//
//        cout << endl;
//
//        cout << "Sortowanie fast-sort dla: " << i << " wynioslo: " << countTime(shelf_3, FAST) << "ms.";
//
//        shelf_3->show();
//
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
        shelfToSort->fastSort();
    }

    end = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();

    return (end - start);
}

void Benchmark::doSort(shared_ptr<Shelf> *shelf, int i, SortType sortType) {
    string sortStr;
    if (sortType == PRIMITIVE)
        sortStr = "prymitywne";
    else if (sortType == PATTERN)
        sortStr = "pattern-sort";
    else
        sortStr = "szybkie";
    cout << "Sortowanie " << sortStr << " dla: " << i << " wynioslo: " << countTime(*shelf, sortType) << "ms." << endl;
}
