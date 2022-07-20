/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (1 == nums.size()) {
      return nums[0];
    }
    std::vector<int> memo1(nums.size(), -1);
    std::vector<int> memo2(nums.size(), -1);
    return std::max(dp(nums, 1, nums.size() - 1, memo1),
                    dp(nums, 0, nums.size() - 2, memo2));
  }

  int dp(const vector<int>& nums, int start, int end, std::vector<int>& memo) {
    if (start > end) {
      return 0;
    }
    if (-1 != memo[start]) {
      return memo[start];
    }

    memo[start] = std::max(dp(nums, start + 1, end, memo),
                           nums[start] + dp(nums, start + 2, end, memo));

    return memo[start];
  }
};
// @lc code=end
