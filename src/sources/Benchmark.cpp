#include <iostream>
#include <thread>
#include "../headers/Benchmark.h"

Benchmark::Benchmark() : precision(DEFAULT_PRECISION) {
}

void Benchmark::runUser() {
    auto inputVector = readInputVector();
    runBenchmark(inputVector);
}

void Benchmark::runRandom(int startFrom, int endIn, int step) {
    int p = 25;
    cout << "Podaj wartosc parametru 'p', ktory okresla szanse wylosowania "
            "nastepnego elementu tablicy, takiego samego, jak poprzedni" << endl;

    while (true) {
        cin >> p;
        if (p >= 0 && p <= 100)
            break;
        else
            cout << "'p' musi byc z przedzialu [0;100]";
    }

    for (int i = startFrom; i <= endIn; i += step) {
        auto inputVector = (new Generator(i, p))->getInitVector();
        runBenchmark(inputVector);
    }
}

void Benchmark::runBenchmark(const vector<int> &inputVector) {
    shelf_1.reset(new Shelf(inputVector));
    shelf_2.reset(new Shelf(inputVector));
    shelf_3.reset(new Shelf(inputVector));

    shared_ptr<long> dataSet(new long[7]);
    dataSet.get()[0] = inputVector.size();

    long runTime = countTime(shelf_1, PRIMITIVE);
    dataSet.get()[1] = runTime;
    dataSet.get()[2] = shelf_1->getMovesList().size();

    runTime = countTime(shelf_2, PATTERN);
    dataSet.get()[3] = runTime;
    dataSet.get()[4] = shelf_2->getMovesList().size();

    runTime = countTime(shelf_3, FAST);
    dataSet.get()[5] = runTime;
    dataSet.get()[6] = shelf_3->getMovesList().size();

    resultsVector.push_back(dataSet);
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

const vector<int> Benchmark::readInputVector() {
    cout << "Wpisz wektor skladajacy sie z liczb 0-3. Wpisz '-1', zeby zakonczyc" << endl;

    vector<int> inputVector;
    while (true) {
        int readNum;
        cin >> readNum;
        if (readNum == -1)
            break;
        else if (readNum >= 0 && readNum <= 3)
            inputVector.push_back(readNum);
        else
            cout << "Podales zla liczbe!";
    }

    return inputVector;
}
