#include "../headers/Generator.h"

Generator::Generator(int size) {
    initVector.clear();

    for (int i = 0; i < size; i++) {
        int tmp = rand() % DIV;
        initVector.push_back(tmp);
    }
}

Generator::Generator(int size, int p) {
    initVector.clear();

    int tmp = rand() % DIV;
    initVector.push_back(tmp);

    for (unsigned i = 1; i < size; i++) {
        int toss = rand() % MAX_TOSS;
        int prev = initVector.at(i - 1);

        if (toss < p) {
            initVector.push_back(prev);
        } else {
            int substract = MAX_TOSS - p;
            toss -= p;

            if ((double) toss / substract <= 1.0 / 3.0) {
                initVector.push_back((prev + 1) % DIV);
            } else if ((double) toss / substract <= 2.0 / 3.0) {
                initVector.push_back((prev + 2) % DIV);
            } else {
                initVector.push_back((prev + 3) % DIV);
            }
        }
    }
}