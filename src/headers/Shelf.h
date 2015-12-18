#ifndef AAL_SHELF_H
#define AAL_SHELF_H

#include <vector>
#include <iosfwd>

using namespace std;

class Shelf {
private:
    const unsigned long size;
    int startIdx = 0;
    int counter[4];
    int *tab;
    vector<int> movesList;

public:
    Shelf(const unsigned long size);

    Shelf(const vector<int> &initVector);

    void sort();

    void patternSort();

    int findPattern(const int color, const int endPos);

    void moveToBeg(int pos);

    int findColorPos(const int color);

    void move(const int pos);

    void show();

    int *getTab() const {
        return tab;
    }

    const vector<int> &getMovesList() const {
        return movesList;
    }
};


#endif //AAL_SHELF_H
