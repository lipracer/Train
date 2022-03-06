
#include <string>
#include <unordered_map>
#include <vector>

#include "type.h"

namespace lskd {
std::vector<int> twoSum(const std::vector<int> &nums, int target);

std::string toString(ListNode *list);

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

int lengthOfLongestSubstring(std::string s);

double findMedianSortedArrays(const std::vector<int> &nums1,
                              const std::vector<int> &nums2);

std::string longestPalindrome(std::string s);

std::string convert(std::string s, int numRows);

int reverse(int x);

void buildTree(tree *root, size_t size);

int findRecentAncer(tree root, int lhs, int rhs);

int myAtoi(std::string s);

bool isPalindrome(int x);

bool isMatch(const std::string& s, const std::string& p);

int maxArea(const std::vector<int> &height);

void heapSort(ArrayRef<int> array);

// 执行用时：
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 5.8 MB
// , 在所有 C++ 提交中击败了
// 84.96%
// 的用户
// 通过测试用例：
// 3999 / 3999
std::string intToRoman(int num);

// 执行用时：
// 4 ms
// , 在所有 C++ 提交中击败了
// 95.85%
// 的用户
// 内存消耗：
// 5.9 MB
// , 在所有 C++ 提交中击败了
// 81.55%
// 的用户
// 通过测试用例：
int romanToInt(const std::string& s);

// refine with stringView
std::string longestCommonPrefix(const std::vector<std::string> &strs);

void sortArray(ArrayRef<int> array, int k1, int k2);

std::vector<std::vector<int>> simplePermutationImpl(ArrayRef<int> data);

template <size_t N> class IntegralN {
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

  explicit IntegralN(const std::string &str) : IntegralN() {
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
      data_.push_back(*it - '0');
    }
  }
  explicit IntegralN(const std::vector<char> &buf)
      : data_(buf.begin(), buf.end()) {}
  IntegralN(const IntegralN &other) : data_(other.data_) {}

  const std::vector<char> &data() const { return data_; }
  std::vector<char> &data() { return data_; }

  explicit operator int64_t() { return 0; }

  friend IntegralN operator+(const IntegralN &lhs, const IntegralN &rhs) {
    assert(lhs.data().size() && rhs.data().size());

    const IntegralN *lhs_ptr = nullptr;
    const IntegralN *rhs_ptr = nullptr;
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
    if (sum)
      result.data().push_back(sum);
    return result;
  }
  friend bool operator==(const IntegralN &lhs, const IntegralN &rhs) {
    return lhs.data() == rhs.data();
  }
  friend std::ostream &operator<<(std::ostream &os, const IntegralN &rhs) {
    for (auto it = rhs.data().rbegin(); it != rhs.data().rend(); ++it) {
      os << char(*it + '0');
    }
    return os;
  }
};

} // namespace lskd