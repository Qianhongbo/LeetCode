/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    std::vector<int> res{1};
    int theSize = nums.size();
    for (int i{1}; i < theSize; i++) {
      int theLastNum = res.back();
      res.push_back(nums[i - 1] * theLastNum);
    }

    int right{1};
    for (int i{theSize - 2}; i >= 0; i--) {
      right *= nums[i + 1];
      res[i] = res[i] * right;
    }

    return res;
  }
};
// @lc code=end
