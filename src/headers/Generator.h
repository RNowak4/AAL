#ifndef AAL_GENERATOR_H
#define AAL_GENERATOR_H

#include <cstdlib>
#include <vector>

using namespace std;

class Generator {
private:
    const static int MAX_TOSS = 101;
    const static int DIV = 4;
    vector<int> initVector;

public:
    Generator(int size);

    Generator(int size, int p);

    const vector<int> &getInitVector() const {
        return initVector;
    }
};


#endif //AAL_GENERATOR_H
