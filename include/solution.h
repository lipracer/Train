
#include <vector>
#include <unordered_map>
#include <string>

namespace Solution {
std::vector<int> twoSum(const std::vector<int> &nums, int target);

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::string toString(ListNode *list);

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

int lengthOfLongestSubstring(std::string s);

double findMedianSortedArrays(const std::vector<int> &nums1,
                              const std::vector<int> &nums2);

std::string longestPalindrome(std::string s);

std::string convert(std::string s, int numRows);

int reverse(int x);

struct TreeNode {
  TreeNode* lhs;
  TreeNode* rhs;
  int idx;
};
typedef TreeNode* tree;

void buildTree(tree *root, size_t size);

int findRecentAncer(tree root, int lhs, int rhs);

int myAtoi(std::string s);

bool isPalindrome(int x);

bool isMatch(const std::string& s, const std::string& p);

int maxArea(const std::vector<int> &height);

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
}