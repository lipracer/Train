#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <bitset>

#include "solution.h"
#include "gtest/gtest.h"

using namespace std;
using namespace Solution;

TEST(OtherTrain, RoateSquareMatrix) {
    
}


TEST(LeetCodeTrain, TwoNumberSum) {
  auto locs = Solution::twoSum({2, 7, 11, 15}, 9);
  EXPECT_EQ(locs[0], 0);
  EXPECT_EQ(locs[1], 1);
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

TEST(LeetCodeTrain, findMedianSortedArrays) {
  std::cout << findMedianSortedArrays({1, 3}, {2}) << std::endl;
  std::cout << findMedianSortedArrays({1, 2}, {3, 4}) << std::endl;
  std::cout << findMedianSortedArrays({0, 0}, {0, 0}) << std::endl;
  std::cout << findMedianSortedArrays({}, {1}) << std::endl;
  std::cout << findMedianSortedArrays({2}, {}) << std::endl;
}

TEST(LeetCodeTrain, longestPalindrome) {
  std::cout << longestPalindrome("babad") << std::endl;
  std::cout << longestPalindrome("cbbd") << std::endl;
  std::cout << longestPalindrome("a") << std::endl;
  std::cout << longestPalindrome("ac") << std::endl;
  std::cout << longestPalindrome("aacabdkacaa") << std::endl; 
}

TEST(LeetCodeTrain, convert) {
  std::cout << convert("PAYPALISHIRING", 3) << std::endl;
  std::cout << convert("PAYPALISHIRING", 4) << std::endl;
  std::cout << convert("A", 1) << std::endl;
  std::cout << convert("A", 2) << std::endl;
  std::cout << convert("ABC", 2) << std::endl;
}


TEST(LeetCodeTrain, reverse) {
  std::cout << reverse(123) << std::endl;
  std::cout << reverse(-123) << std::endl;
  std::cout << reverse(120) << std::endl;
  std::cout << reverse(0) << std::endl;
  std::cout << reverse(1534236469) << std::endl;
  std::cout << reverse(-2147483412) << std::endl;
}

// TEST(LeetCodeTrain, findRecentAncer) {
//   tree mtree;
//   buildTree(&mtree, 20);
//   std::cout << findRecentAncer(mtree, 4, 7) << std::endl;
// }

TEST(LeetCodeTrain, myAtoi) {
  std::cout << myAtoi("42") << std::endl;
  std::cout << myAtoi("-42") << std::endl;
  std::cout << myAtoi("4193 with words") << std::endl;
  std::cout << myAtoi("words and 987") << std::endl;
  std::cout << myAtoi("-91283472332") << std::endl;
  std::cout << myAtoi("+1") << std::endl;
  std::cout << myAtoi("-+1") << std::endl;
  std::cout << myAtoi("20000000000000000000") << std::endl;
  
}

TEST(LeetCodeTrain, isPalindrome) {
  std::cout << isPalindrome(-121) << std::endl;
  std::cout << isPalindrome(121) << std::endl;
  std::cout << isPalindrome(1) << std::endl;
  std::cout << isPalindrome(1221) << std::endl;
  const char *p = "1234";
  const char *n = p + 1;
  std::cout << p - n << std::endl;
}

TEST(LeetCodeTrain, IsMatch) {
  EXPECT_FALSE(isMatch("aa", "a"));
  EXPECT_FALSE(isMatch("aa", "a*"));
  EXPECT_FALSE(isMatch("ab", ".*"));
  EXPECT_FALSE(isMatch("aab", "c*a*b"));
  EXPECT_FALSE(isMatch("mississippi", "mis*is*p*."));
}

TEST(LeetCodeTrain, maxArea) {
  EXPECT_EQ(49, maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}));
  EXPECT_EQ(1, maxArea({1, 1}));
  EXPECT_EQ(16, maxArea({4, 3, 2, 1, 4}));
  EXPECT_EQ(2, maxArea({1, 2, 1}));
}
