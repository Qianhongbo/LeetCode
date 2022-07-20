/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
 public:
  int jump(vector<int>& nums) {
    int sz = nums.size();
    int jumps{0};
    int farthest{0};
    int end{0};
    // should be sz - 1, because we only want to reach the last index
    for (int i{0}; i < sz - 1; i++) {
      farthest = std::max(farthest, i + nums[i]);
      if (end == i) {
        jumps++;
        end = farthest;
      }
    }

    return jumps;
  }
};
// @lc code=end
