/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int sz = nums.size();
    int farthest{0};
    for (int i{0}; i < sz - 1; i++) {
      if (farthest < i) {
        return false;
      }
      farthest = std::max(farthest, i + nums[i]);
    }

    return farthest >= sz - 1;
  }
};
// @lc code=end
