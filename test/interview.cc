#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>

#include "solution.h"
#include "gtest/gtest.h"

using namespace std;
using namespace Solution;
using namespace type;

TEST(QuitSort, sortArray) {
  int array[] = {9, 5, 2, 6, 4, 1, 8};
  sortArray(array, 3, 7);
  std::cout << ArrayRef<int>(array) << std::endl;
}

template <typename T>
struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    T data;
};

TEST(commonAncestors, simple) {

}