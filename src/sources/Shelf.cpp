#include "../headers/Shelf.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>

Shelf::Shelf(const unsigned long size) : size(size) {
    tab = new int[size];

    for (int i = 0; i < size; i++) {
        int tmp = rand() % 4;
        ++counter[tmp];
        tab[i] = tmp;
    }
}

Shelf::Shelf(const vector<int> &initVector) : size(initVector.size()) {
    tab = new int[size];

    int j = 0;
    for (auto i : initVector) {
        ++counter[i];
        tab[j++] = i;
    }
}

void Shelf::sort() {
    if (counter[3] < 5) {
        cout << "Maybe impossible" << endl;
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < counter[i]; j++) {
            moveToBeg(findColorPos(i));
            startIdx++;
        }
    }
}


void Shelf::patternSort() {
    if (counter[3] < 5) {
        cout << "Maybe impossible" << endl;
        return;
    }

    int patternPos, endPos;
    for (int i = 0; i < 3; i++) {
        endPos = size;

        while ((patternPos = findPattern(i, endPos)) != -1) {
            endPos -= 4;
            move(patternPos);
        }

        int moved = size - endPos;

        // jesli cos znalezlismy
        if (endPos != size) {
            // liczba nieuporzadkowanych pojemnikow
            int l = endPos - startIdx;

            if (l % 4 == 0) {
                for (int j = 0; j < l / 4; j++) {
                    move(startIdx);
                }
            } else {
                for (int j = 0; j < l / 4 + 1; j++) {
                    move(startIdx);
                }

                if (l % 4 == 1) {
                    moved -= 3;
                } else if (l % 4 == 2) {
                    moved -= 2;
                } else {
                    moved -= 1;
                }
            }
        }

        startIdx += moved;
        counter[i] -= moved;

        for (int j = 0; j < counter[i]; j++) {
            moveToBeg(findColorPos(i));
            startIdx++;
        }
    }
}

int Shelf::findPattern(const int color, const int endPos) {
    for (int i = startIdx, j = counter[color]; i < size; i++) {
        if (i > (endPos - 4) || i > (size - 4) || j < 4)
            break;

        if (tab[i] == color) {
            j--;

            if (tab[i + 1] == color && tab[i + 2] == color && tab[i + 3] == color)
                return i;
        }
    }

    // nie znaleziono
    return -1;
}


void Shelf::moveToBeg(int pos) {
    if (pos == startIdx)
        return;

    int num = (size - 1) - startIdx;

    if (num > 6) {
        if ((pos - startIdx) % 4 == 0) {
            for (int i = 0; i < (pos - startIdx) / 4; i++) {
                move(startIdx);
            }
        } else {
            if (num % 4 == 0) {
                if (pos + 4 >= size) {
                    move(startIdx);
                    pos -= 4;
                }

                if (pos - 3 < startIdx) {
                    move(pos);
                    pos = size - 4;
                }

                move(pos - 3);
                for (int i = 0; i < num / 4; i++) {
                    move(startIdx);
                }
            } else if (num % 4 == 1) {
                if (pos + 4 >= size) {
                    move(startIdx);
                    pos -= 4;
                }

                if (pos - 2 < startIdx) {
                    move(pos);
                    pos = size - 4;
                }

                move(pos - 2);
                for (int i = 0; i < num / 4; i++) {
                    move(startIdx);
                }
            } else if (num % 4 == 2) {
                if (pos + 4 >= size) {
                    move(startIdx);
                    pos -= 4;
                }

                if (pos - 1 < startIdx) {
                    move(pos);
                    pos = size - 4;
                }

                move(pos - 1);
                for (int i = 0; i < num / 4; i++) {
                    move(startIdx);
                }
            } else {
                if (pos + 4 >= size) {
                    move(startIdx);
                    pos -= 4;
                }

                move(pos);
                for (int i = 0; i < num / 4; i++) {
                    move(startIdx);
                }
            }
        }
    } else if (num == 6) {
        switch (pos - startIdx) {
            case 1:
                move(startIdx);
                move(startIdx);

                break;

            case 2:
                move(startIdx);
                move(startIdx + 1);
                move(startIdx);
                move(startIdx);

                break;

            case 3:
                move(startIdx + 2);
                move(startIdx);

                break;

            case 4:
                move(startIdx);

                break;

            case 5:
                move(startIdx + 1);
                move(startIdx);
                move(startIdx);

                break;

            case 6:
                move(startIdx);
                move(startIdx);
                move(startIdx + 1);
                move(startIdx);
                move(startIdx);

                break;
            default:
                break;
        }
    } else if (num == 5) {
        switch (pos - startIdx) {
            case 1:
                move(startIdx);
                move(startIdx + 1);
                move(startIdx);

                break;

            case 2:
                move(startIdx);
                move(startIdx);

                break;

            case 3:
                move(startIdx + 1);
                move(startIdx);

                break;

            case 4:
                move(startIdx);

                break;

            case 5:
                move(startIdx);
                move(startIdx);
                move(startIdx + 1);
                move(startIdx);

                break;
            default:
                break;
        }
    }
}

int Shelf::findColorPos(const int color) {
    if (color < 0 || color > 3)
        throw runtime_error("Bad color ID!");

    int i = startIdx;

    //noinspection StatementWithEmptyBody
    while (i < size && tab[i++] != color);

    return --i;
}

void Shelf::move(const int pos) {
    movesList.push_back(pos);

    int A, B, C, D;
    A = tab[pos];
    B = tab[pos + 1];
    C = tab[pos + 2];
    D = tab[pos + 3];

    for (int i = pos + 4; i < size; i++) {
        tab[i - 4] = tab[i];
    }

    tab[size - 4] = A;
    tab[size - 3] = B;
    tab[size - 2] = C;
    tab[size - 1] = D;
}

void Shelf::show() {
    string ret = "";

    for (int i = 0; i < size; i++) {
        if (tab[i] == 0)
            ret += "C";
        else if (tab[i] == 1)
            ret += "M";
        else if (tab[i] == 2) {
            ret += "Y";
        } else if (tab[i] == 3) {
            ret += "K";
        } else
            throw runtime_error("Bad value");
    }

    cout << ret << endl;
}
