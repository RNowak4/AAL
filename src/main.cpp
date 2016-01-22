#include <cmath>
#include <iostream>
#include <string.h>
#include <iomanip>
#include "headers/Benchmark.h"

using namespace std;

enum {
    BAD_INPUT_ARGUMENTS = -11
};

void printHelp() {
    cout << "-random - randomly generated shelf" << endl;
    cout << "-user - user writes shelf" << endl;
    cout << "-table - program prints statistics after end" << endl;
    cout << "-stepByStep - program shows stepByStep solution" << endl;
    cout << "-help - program shows help" << endl;
}

int main(int argc, char **argv) {
    srand((unsigned int) time(NULL));

    bool randomInput = true;
    bool showTable = false;
    bool verboseMode = false;
    for (int i = 1; i < argc; ++i) {
        if (strcmp("-random", argv[i]) == 0)
            randomInput = true;
        else if (strcmp("-user", argv[i]) == 0)
            randomInput = false;
        else if (strcmp("-table", argv[i]) == 0)
            showTable = true;
        else if (strcmp("-help", argv[i]) == 0)
            printHelp();
        else if (strcmp("-stepByStep", argv[i]) == 0)
            verboseMode = true;
        else
            return BAD_INPUT_ARGUMENTS;
    }

    shared_ptr<Benchmark> benchmark(new Benchmark());

    if (verboseMode) {
        benchmark->stepByStep(50, 25, FAST);
    } else if (randomInput) {
        cout << "Podaj wartosci poczatka, konca oraz kroku:" << endl;
        unsigned start, end, step;
        cin >> start >> end >> step;
        benchmark->runRandom(start, end, step);
    }
    else {
        benchmark->runUser();
    }

    if (showTable && !verboseMode) {
        benchmark->printResults();
    }

    return 0;
}