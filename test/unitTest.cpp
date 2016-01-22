#include "gtest/gtest.h"
#include "../src/headers/Shelf.h"
#include "../src/headers/Generator.h"
#include "../src/headers/Benchmark.h"

using namespace std;

enum {
    TESTS_START = 100,
    TESTS_END = 1600,
    TESTS_STEP = 100,
};

void test(SortType sortType);

TEST(sortTest, sortTest_primitive_Test) {
    srand((unsigned int) time(NULL));

   test(PRIMITIVE);
}

TEST(sortTest, sortTest_pattern_Test) {
    test(PATTERN);
}

TEST(sortTest, sortTest_fast_Test) {
    test(FAST);
}


void test(SortType sortType) {
    shared_ptr<Shelf> shelf;
    for (int i = TESTS_START; i <= TESTS_END; i += TESTS_STEP) {

        int p = rand() % 100;
        shelf.reset(new Shelf(Generator(i, p).getInitVector()));

        if (sortType == PRIMITIVE)
            shelf->sort();
        else if (sortType == PATTERN)
            shelf->patternSort();
        else
            shelf->fastSort();

        ASSERT_TRUE(shelf->testShelf());
    }
}