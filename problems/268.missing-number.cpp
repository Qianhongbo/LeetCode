/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int res{0};
    int sz = nums.size();
    res ^= sz;
    for (int i{0}; i < sz; i++) {
      res ^= i ^ nums[i];
    }

    return res;
  }
};
// @lc code=end
