/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // first need to sort before using two pointer method
    std::sort(nums.begin(), nums.end());
    return nSumTarget(nums, 4, 0, target);
  }

  vector<vector<int>> nSumTarget(vector<int>& nums, int n, int start, long long target) {
    int sz = nums.size();
    std::vector<std::vector<int>> res;

    if (n == 2) {
      // regular 2 sum template
      int l = start, r = sz - 1;
      while (l < r) {
        int left = nums[l], right = nums[r];
        int sum = left + right;
        if (sum < target) {
          while (l < r && nums[l] == left) l++;
        } else if (sum > target) {
          while (l < r && nums[r] == right) r--;
        } else {
          res.push_back({left, right});
          while (l < r && nums[l] == left) l++;
          while (l < r && nums[r] == right) r--;
        }
      }
    } else {
      for (int i{start}; i < sz; i++) {
        std::vector<std::vector<int>> sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
        for (std::vector<int>& arr : sub) {
          arr.push_back(nums[i]);
          res.push_back(arr);
        }
        while (i < sz - 1 && nums[i] == nums[i + 1]) i++;
      }
    }

    return res;
  }
};
// @lc code=end
