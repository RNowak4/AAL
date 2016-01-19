#include <cmath>
#include <iostream>
#include <string.h>
#include <iomanip>
#include "headers/Benchmark.h"

using namespace std;

enum {
    BAD_INPUT_ARGUMENTS = -11,
    DEFAULT_TABLE_WIDTH = 15
};

void showAlgorithmInfo(const string &algorithmInfo, int complexity, const vector<shared_ptr<long> > &resultVector,
                       int start, int end) {
    cout.width(DEFAULT_TABLE_WIDTH * 4);
    cout << algorithmInfo << endl;

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

void printTable(const vector<shared_ptr<long>> &resultVector) {
    showAlgorithmInfo("Slow sort - O(n^3)", 3, resultVector, 1, 2);
    showAlgorithmInfo("Pattern sort - O(n^3)", 3, resultVector, 3, 4);
    showAlgorithmInfo("Fast sort - O(n^2)", 3, resultVector, 5, 6);
}

void printHelp() {
    cout << "-random - randomly generated shelf" << endl;
    cout << "-user - user writes shelf" << endl;
    cout << "-table - program prints statistics after end" << endl;
    cout << "-precise [value] - precise of " << endl;
    cout << "-help - program shows help" << endl;
}

int main(int argc, char **argv) {
    srand((unsigned int) time(NULL));

    bool randomInput = true;
    bool showTable = false;
    int precision = DEFAULT_PRECISION;
    for (int i = 1; i < argc; ++i) {
        if (strcmp("-random", argv[i]) == 0)
            randomInput = true;
        else if (strcmp("-user", argv[i]) == 0)
            randomInput = false;
        else if (strcmp("-table", argv[i]) == 0)
            showTable = true;
        else if (strcmp("-help", argv[i]) == 0)
            printHelp();
        else
            return BAD_INPUT_ARGUMENTS;
    }

    shared_ptr<Benchmark> benchmark(new Benchmark());
    benchmark->setPrecision(precision);
    if (randomInput) {
        cout << "Podajwartosci poczatka, konca oraz kroku:" << endl;
        unsigned start, end, step;
        cin >> start >> end >> step;
        benchmark->runRandom(start, end, step);
    }
    else {
        benchmark->runUser();
    }

    if (showTable) {
        printTable(benchmark->getResultsVector());
    }

    return 0;
}