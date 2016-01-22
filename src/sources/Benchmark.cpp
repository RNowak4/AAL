#include <iostream>
#include <thread>
#include <iomanip>
#include <cmath>
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
        auto inputVector = (Generator(i, p)).getInitVector();
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

void Benchmark::showAlgorithmInfo(const string &algorithmInfo, int complexity,
                                  const vector<shared_ptr<long> > &resultVector, int start, int end) const {

    cout << setw(DEFAULT_TABLE_WIDTH * 4) << setiosflags(ios::left) << algorithmInfo << endl;
    cout << setw(DEFAULT_TABLE_WIDTH) << setiosflags(ios::left) << "input size";
    cout << setw(DEFAULT_TABLE_WIDTH) << setiosflags(ios::left) << "time";
    cout << setw(DEFAULT_TABLE_WIDTH) << setiosflags(ios::left) << "moves";
    cout << setw(DEFAULT_TABLE_WIDTH) << setiosflags(ios::left) << "q parameter";
    cout << endl;

    double tMed = resultVector.at(resultVector.size() / 2).get()[start];
    double TMed = pow(resultVector.at(resultVector.size() / 2).get()[0], complexity);
    for (unsigned long i = 0; i < resultVector.size(); ++i) {
        const long *dataSet = resultVector.at(i).get();
        cout << setw(DEFAULT_TABLE_WIDTH) << setiosflags(ios::left) << dataSet[0];
        for (int j = start; j <= end; ++j) {
            cout << setw(DEFAULT_TABLE_WIDTH) << setiosflags(ios::left) << dataSet[j];
        }
        double T = pow(dataSet[0], complexity);
        double q = (dataSet[start] * TMed) / (T * tMed);
        cout << setw(DEFAULT_TABLE_WIDTH) << setiosflags(ios::left) << q;
        cout << endl;
    }
    cout << endl;
}

void Benchmark::printResults() const {
    showAlgorithmInfo("Slow sort - O(n^3)", 3, resultsVector, 1, 2);
    showAlgorithmInfo("Pattern sort - O(n^3)", 3, resultsVector, 3, 4);
    showAlgorithmInfo("Fast sort - O(n^3)", 3, resultsVector, 5, 6);
}

void Benchmark::stepByStep(const int size, const int p, const SortType type) const {
    auto vector = (Generator(size, p)).getInitVector();
    shared_ptr<Shelf> shelfToSort(new Shelf(vector));
    shared_ptr<Shelf> shelfToPresent(new Shelf(vector));

    if (type == PRIMITIVE)
        shelfToSort->sort();
    else if (type == PATTERN)
        shelfToSort->patternSort();
    else
        shelfToSort->fastSort();

    shelfToPresent->showStepByStep(shelfToSort->getMovesList());

}
