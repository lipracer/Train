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

template <size_t N>
class IntegralN {
 private:
  std::vector<char> data_;
  IntegralN() { data_.reserve(16); }

  size_t size() const { return data_.size(); }

 public:
  IntegralN(int64_t n) : IntegralN() {
    do {
      data_.push_back(n % N);
      n = n / N;
    } while (n);
  }

  explicit IntegralN(const std::string& str) : IntegralN() {
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
      data_.push_back(*it - '0');
    }
  }
  explicit IntegralN(const std::vector<char>& buf) : data_(buf.begin(), buf.end()) {}
  IntegralN(const IntegralN& other) : data_(other.data_) {}

  const std::vector<char>& data() const { return data_; }
  std::vector<char>& data() { return data_; }

  explicit operator int64_t() { return 0; }

  friend IntegralN operator+(const IntegralN& lhs, const IntegralN& rhs) {
    assert(lhs.data().size() && rhs.data().size());

    const IntegralN* lhs_ptr = nullptr;
    const IntegralN* rhs_ptr = nullptr;
    std::tie(lhs_ptr, rhs_ptr) = lhs.size() < rhs.size()
                                     ? std::make_tuple(&lhs, &rhs)
                                     : std::make_tuple(&lhs, &rhs);
    IntegralN result(*lhs_ptr);
    result.data().resize(rhs_ptr->size(), 0);
    auto lhs_first = result.data().begin();
    auto rhs_first = rhs_ptr->data().begin();
    size_t sum = 0;
    while (lhs_first != result.data().end()) {
      sum = *lhs_first + *rhs_first + sum;
      *lhs_first = (sum % N);
      sum /= N;
      ++lhs_first;
      ++rhs_first;
    }
    if (sum) result.data().push_back(sum);
    return result;
  }
  friend bool operator==(const IntegralN& lhs, const IntegralN& rhs) {
    return lhs.data() == rhs.data();
  }
  friend std::ostream& operator<<(std::ostream& os, const IntegralN& rhs) {
    for (auto it = rhs.data().rbegin(); it != rhs.data().rend(); ++it) {
      os << char(*it + '0');
    }
    return os;
  }

};

TEST(IntegralN26, add0) {
  EXPECT_EQ(IntegralN<26>(26) + IntegralN<26>(26), IntegralN<26>(52));
}

TEST(IntegralN26, add1) {
  std::cout << IntegralN<26>(26) + IntegralN<26>(26 * 26) << std::endl;
  EXPECT_EQ(IntegralN<26>(26) + IntegralN<26>(26 * 26), IntegralN<26>("110"));
}