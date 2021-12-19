
#include <vector>
#include <unordered_map>
#include <string>
#include "type.h"

namespace Solution {
std::vector<int> twoSum(const std::vector<int> &nums, int target);

std::string toString(type::ListNode *list);

type::ListNode *addTwoNumbers(type::ListNode *l1, type::ListNode *l2);

int lengthOfLongestSubstring(std::string s);

double findMedianSortedArrays(const std::vector<int> &nums1,
                              const std::vector<int> &nums2);

std::string longestPalindrome(std::string s);

std::string convert(std::string s, int numRows);

int reverse(int x);

void buildTree(type::tree *root, size_t size);

int findRecentAncer(type::tree root, int lhs, int rhs);

int myAtoi(std::string s);

bool isPalindrome(int x);

bool isMatch(const std::string& s, const std::string& p);

int maxArea(const std::vector<int> &height);

void heapSort(type::ArrayRef<int> array);

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

void sortArray(type::ArrayRef<int> array, int k1, int k2);

std::vector<std::vector<int>> simplePermutationImpl(type::ArrayRef<int> data);

}