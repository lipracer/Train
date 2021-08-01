
#include "solution.h"
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>

namespace Solution {
std::vector<int> twoSum(const std::vector<int> &nums, int target) {
  std::vector<int> result(2, 0);
  std::unordered_map<int, size_t> map;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (map.end() != map.find(nums[i])) {
      result[0] = map[nums[i]];
      result[1] = i;
      return result;
    }
    map.insert({target - nums[i], i});
  }
  return {};
}

std::string toString(ListNode *list) {
  std::stringstream ss;
  ss << "[";
  while (list) {
    ss << list->val << ",";
    list = list->next;
  }
  if (1 == ss.str().size()) {
    ss << "]";
    return ss.str();
  }
  ss.seekp(-1, std::ios::cur);
  ss << "]";
  return ss.str();
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *result = nullptr;
  ListNode **cur_node = &result;
  size_t sum = 0;
  while (l1 || l2 || sum) {
    if (l1)
      sum += l1->val;
    if (l2)
      sum += l2->val;
    *cur_node = new ListNode(sum % 10);
    sum /= 10;
    if (l1)
      l1 = l1->next;
    if (l2)
      l2 = l2->next;
    cur_node = &((*cur_node)->next);
  }
  return result;
}

// int lengthOfLongestSubstring(std::string s) {
//   using range = std::pair<int, int>;
//   std::vector<range> ranges;
//   ranges.reserve(256);
//   for (size_t i = 0; i < s.size() - 1; ++i) {
//     range tmp{-1, -1};
//     if (s[i] == s[i + 1]) {
//       tmp.first = i;
//     } else {
//       if (-1 != tmp.first) {
//         tmp.second = i + 1;
//         ranges.push_back(tmp);
//       }
//     }
//   }
//   if (ranges.empty()) {
//     return s.size();
//   }
//   size_t first = ranges.front().first;
//   for (size_t i = 0; i < ranges.size() - 1; ++i) {
//     if (first < ranges[i + 1].first - ranges[i].first) {
//       first = ranges[i + 1].first - ranges[i].first;
//     }
//   }
//   size_t last = s.size() - ranges.back().second;
//   return std::max(first, last);
// }

int lengthOfLongestSubstring(std::string s) {
  if (s.empty()) {
    return 0;
  }
  std::unordered_map<char, size_t> bucket;
  size_t max_size = 1;
  bucket.reserve(256);
  bucket.emplace(s.front(), 0);
  std::pair<size_t, size_t> window(0, 1);
  while (window.second < s.size()) {
    if (bucket.end() == bucket.find(s[window.second])) {
      bucket.emplace(s[window.second], window.second);
      if (max_size < window.second - window.first + 1) {
        max_size = window.second - window.first + 1;
      }
    } else {
      while (window.first <= bucket[s[window.second]]) {
        bucket.erase(s[window.first]);
        ++window.first;
      }
      bucket[s[window.second]] = window.second;
    }
    ++window.second;
  }
  return max_size;
}

// 执行用时：
// 36 ms
// , 在所有 C++ 提交中击败了
// 74.36%
// 的用户
// 内存消耗：
// 86.8 MB
// , 在所有 C++ 提交中击败了
// 89.05%
// 的用户

double findMedianSortedArrays(const std::vector<int> &nums1,
                              const std::vector<int> &nums2) {
  auto lhs = nums1.begin();
  auto rhs = nums2.begin();
  auto total = nums1.size() + nums2.size();
  size_t loc = (total - 1) / 2;
  int v0 = 0, v1 = 0;
  auto get_cur_value_increase = [&]() {
    if (lhs != nums1.end() && rhs != nums2.end()) {
      if (*lhs < *rhs) {
        return *lhs++;
      } else {
        return *rhs++;
      }
    } else if (lhs != nums1.end()) {
      return *lhs++;
    } else if (rhs != nums2.end()) {
      return *rhs++;
    }
  };
  for (size_t i = 0;; ++i) {
    v1 = v0 = get_cur_value_increase();
    if (i == loc) {
      break;
    }
  }
  if (total % 2 == 0) {
    v1 = get_cur_value_increase();
  }
  return (v0 + v1) / static_cast<double>(2);
}

std::string longestPalindrome(std::string s) {
  auto lhs = s.c_str();
  auto rhs = s.c_str();
  size_t index = 0;
  auto increase = [&]() {
    if (index++ % 2) {
      ++rhs;
    } else {
      ++lhs;
    }
  };
  std::pair<const char *, const char *> range{lhs, rhs};
  while (rhs != s.c_str() + s.size()) {
    auto l = lhs;
    auto r = rhs;
    size_t length = 0;
    while (l > s.c_str() - 1 && r < s.c_str() + s.size() && *l == *r) {
      ++length;
      --l;
      ++r;
    }
    if (length > (range.second - range.first + 1) / 2) {
      range = {++l, r};
    }
    increase();
  }
  return std::string(range.first, range.second);
}

// 执行结果：
// 通过
// 显示详情
// 添加备注

// 执行用时：
// 0 ms
// , 在所有 C++ 提交中击败了
// 100.00%
// 的用户
// 内存消耗：
// 8.7 MB
// , 在所有 C++ 提交中击败了
// 68.31%
// 的用户
std::string convert(std::string s, int numRows) {
  if (numRows < 2) {
    return s;
  }
  if (s.length() <= numRows) {
    return s;
  }
  size_t batch_size = (numRows << 1) - 2;
  size_t numCols = (s.length() / batch_size + 1) * 2;
  while (s.length() < batch_size * numCols / 2)
    s.push_back(0);
  std::vector<char> array(numRows * numCols, 0);
  auto str_iter = s.begin();
  auto buf_iter = array.begin();
  while (str_iter != s.end()) {
    if (std::distance(array.begin(), buf_iter) / numRows % 2 == 0) {
      std::copy_n(str_iter, numRows, buf_iter);
      buf_iter += numRows;
      str_iter += numRows;
    } else {
      for (size_t i = 0; i < numRows - 2; ++i) {
        *(buf_iter + numRows - 2 - i) = *str_iter++;
      }
      buf_iter += numRows;   
    }
  }
  std::string result;
  for (size_t i = 0; i < numRows; ++i) {
    for (size_t j = 0; j < numCols; j++) {
      auto chr = *(array.begin() + i + j * numRows);
      if (chr) {
        result.push_back(chr);
      }
    }
  }
  return result;
}

int reverse(int x) {
  int ret = 0;
  while (x) {
    if (ret > std::numeric_limits<int>::max() / 10 ||
        ret < std::numeric_limits<int>::lowest() / 10) {
      return 0;
    }
    ret *= 10;
    ret += x % 10;
    x /= 10;
  }
  return ret;
}
}
