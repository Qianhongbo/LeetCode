/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> res;
  vector<vector<int>> subsets(vector<int>& nums) {
    std::vector<int> track;
    backtrack(nums, 0, track);
    return res;
  }

  void backtrack(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);
    for (int i{start}; i < nums.size(); i++) {
      track.push_back(nums[i]);
      backtrack(nums, i + 1, track);
      track.pop_back();
    }
  }
};
// @lc code=end
