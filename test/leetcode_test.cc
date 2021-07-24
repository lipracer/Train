#include "train_test.h"

#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "solution.h"

using namespace std;
using namespace Solution;

TEST(OtherTrain, RoateSquareMatrix) {
    
}


TEST(LeetCodeTrain, TwoNumberSum) {
  auto locs = Solution::twoSum({2, 7, 11, 15}, 9);
  std::cout << locs << std::endl;
}

TEST(LeetCodeTrain, addTwoNumbers) {
  ListNode *l1 = nullptr;
  ListNode **cur_l1 = &l1;
  ListNode *l2 = nullptr;
  ListNode **cur_l2 = &l2;
  for (size_t i = 0; i < 7; ++i) {
    *cur_l1 = new ListNode(9);
    cur_l1 = &((*cur_l1)->next);
  }
  for (size_t i = 0; i < 4; ++i) {
    *cur_l2 = new ListNode(9);
    cur_l2 = &((*cur_l2)->next);
  }
  std::cout << toString(l1) << std::endl;
  std::cout << toString(l2) << std::endl;
  auto ret = addTwoNumbers(l1, l2);
  std::cout << toString(ret) << std::endl;
}

TEST(LeetCodeTrain, lengthOfLongestSubstring) {
  std::cout << lengthOfLongestSubstring("abcabcbb") << std::endl;
  std::cout << lengthOfLongestSubstring("abc") << std::endl;
  std::cout << lengthOfLongestSubstring("bbbb") << std::endl;
  std::cout << lengthOfLongestSubstring("pwwkew") << std::endl;
}