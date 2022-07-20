/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int sz = nums.size();
    if (sz == 0) {
      return 0;
    }
    std::vector<int> dp(sz, 0);

    dp[0] = nums[0];

    for (int i{1}; i < sz; i++) {
      dp[i] = std::max(nums[i], nums[i] + dp[i - 1]);
    }

    int res = INT_MIN;
    for (int i{0}; i < sz; i++) {
      res = std::max(res, dp[i]);
    }

    return res;
  }
};
// @lc code=end
