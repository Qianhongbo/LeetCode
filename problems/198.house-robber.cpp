/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<int> memo;
  int rob(vector<int>& nums) {
    memo.resize(nums.size(), -1);
    return dp(nums, 0);
  }

  int dp(const vector<int>& nums, int start) {
    if (start >= nums.size()) {
      return 0;
    }

    if (-1 != memo[start]) {
      return memo[start];
    }

    memo[start] = std::max(dp(nums, start + 1),
                       nums[start] + dp(nums, start + 2));;
    return memo[start];
  }
};
// @lc code=end
