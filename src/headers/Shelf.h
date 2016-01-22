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

    ~Shelf();

    void sort();

    void patternSort();

    void fastSort();

    int findPattern(const int color, const int endPos);

    void makeSpaces(const int color);

    void moveFromEnd(const int color, const int pos);

    void moveOtherFromEnd(const int color, const int pos);

    void moveToBeg(int pos);

    void moveToBeg(int pos, int startIdx);

    int findColorPos(const int color) const;

    int findColorPos(const int color, const int startPos) const;

    int findOtherColorPos(const int color) const;

    int findOtherColorPos(const int color, const int startPos) const;

    void move(const int pos);

    void show();

    void showStepByStep(const vector<int> &moves);

    bool testShelf() const;

    const vector<int> &getMovesList() const {
        return movesList;
    }
};


#endif //AAL_SHELF_H
