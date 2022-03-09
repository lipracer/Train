#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>

#include "solution.h"
#include "gtest/gtest.h"
#include "algorithm.hpp"

using namespace std;
using namespace lskd;

TEST(QuitSort, sortArray) {
  int array[] = {9, 5, 2, 6, 4, 1, 8};
  sortArray(array, 3, 7);
  std::cout << ArrayRef<int>(array) << std::endl;
}

TEST(QuitSort, quickSortArray) {
  std::vector<int> array = {9, 5, 2, 6, 4, 1, 8};
  quickSort(array.begin(), array.end());
  std::cout << ArrayRef<int>(array) << std::endl;
  // std::sort;
}

TEST(HeapSort, sortArray) {
  int array[] = {9, 5, 2, 6, 4, 1, 8};
  heapSort(array);
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

TEST(IntegralN26, add0) {
  EXPECT_EQ(IntegralN<26>(26) + IntegralN<26>(26), IntegralN<26>(52));
}

TEST(IntegralN26, add1) {
  std::cout << IntegralN<26>(26) + IntegralN<26>(26 * 26) << std::endl;
  EXPECT_EQ(IntegralN<26>(26) + IntegralN<26>(26 * 26), IntegralN<26>("110"));
}

// give an array the values in the range 1~1000
// you need build a new array, that one of this element value
// is all of origin array elements product exluce it self

void append(const std::vector<int32_t> &array, size_t index,
            std::vector<int32_t> &produce) {
  produce[index] = produce[index - 1] * array[index - 1];
  for (size_t i = 0; i < index - 1; ++i) {
    produce[i] *= array[index];
  }
}

std::vector<int32_t> produce(const std::vector<int32_t> &array) {
  assert(array.size() > 1);
  std::vector<int32_t> result(array.size(), 1);
  result[0] = array[1];
  result[1] = array[0];
  for (size_t i = 2; i < array.size(); ++i) {
    append(array, i, result);
  }
  return result;
}

TEST(produce, tencent) {
  std::vector<int> array = {1, 2, 3};
  auto result = produce(array);
  std::cout << makeArrayRef<int>(result);
}