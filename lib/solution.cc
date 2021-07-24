#include "train_test.h"

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

TEST(OtherTrain, RoateSquareMatrix) {
    
}

namespace Solution {
vector<int> twoSum(const vector<int> &nums, int target) {
  unordered_map<int, size_t> map;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (map.end() != map.find(nums[i])) {
      return {map[nums[i]], i};
    }
    map.insert({target - nums[i], i});
  }
  return {};
}
}

TEST(LeetCodeTrain, TwoNumberSum) {
  auto locs = Solution::twoSum({2, 7, 11, 15}, 9);
  std::cout << locs << std::endl;
}
