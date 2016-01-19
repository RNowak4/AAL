#include <chrono>
#include <iostream>
#include <string.h>
#include "headers/Benchmark.h"

using namespace std;

enum {
    BAD_INPUT_ARGUMENTS = -11,
    DEFAULT_TABLE_WIDTH = 8
};

int main(int argc, char **argv) {
    srand((unsigned int) time(NULL));

    bool randomInput = true;
    bool showTable = false;
    for (int i = 1; i < argc; ++i) {
        if (strcmp("-random", argv[i]) == 0)
            randomInput = true;
        else if (strcmp("-user", argv[i]) == 0)
            randomInput = false;
        else if (strcmp("-table", argv[i]) == 0)
            showTable = true;
        else
            return BAD_INPUT_ARGUMENTS;
    }

    shared_ptr<Benchmark> benchmark;
    if (randomInput) {
        cout << "Podaj wartosci poczatka, konca oraz kroku:" << endl;
        unsigned start, end, step;
        cin >> start >> end >> step;
        benchmark.reset(new Benchmark(start, end, step));
    }
    else
        benchmark.reset(new Benchmark());

    if (showTable) {
        cout.width(DEFAULT_TABLE_WIDTH);
        cout << "inpSize ";
        cout.width(DEFAULT_TABLE_WIDTH);
        cout << "slowSort ";
        cout.width(DEFAULT_TABLE_WIDTH);
        cout << "pattSort ";
        cout.width(DEFAULT_TABLE_WIDTH);
        cout << "fastSort";
        cout << endl;

        auto resultsVector = benchmark->getResultsVector();
        for (unsigned long i = 0; i < resultsVector.size(); ++i) {

            const long *dataSet = resultsVector.at(i).get();
            for (unsigned j = 0; j < 4; ++j) {
                cout.width(DEFAULT_TABLE_WIDTH);
                cout << dataSet[j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}