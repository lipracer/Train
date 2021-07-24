
#include "solution.h"
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

int lengthOfLongestSubstring(std::string s) {
  using range = std::pair<int, int>;
  std::vector<range> ranges;
  ranges.reserve(256);
  for (size_t i = 0; i < s.size() - 1; ++i) {
    range tmp{-1, -1};
    if (s[i] == s[i + 1]) {
      tmp.first = i;
    } else {
      if (-1 != tmp.first) {
        tmp.second = i + 1;
        ranges.push_back(tmp);
      }
    }
  }
  if (ranges.empty()) {
    return s.size();
  }
  size_t first = ranges.front().first;
  for (size_t i = 0; i < ranges.size() - 1; ++i) {
    if (first < ranges[i + 1].first - ranges[i].first) {
      first = ranges[i + 1].first - ranges[i].first;
    }
  }
  size_t last = s.size() - ranges.back().second;
  return std::max(first, last);
}
}