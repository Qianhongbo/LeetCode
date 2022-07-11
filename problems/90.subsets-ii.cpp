/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> res;
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    // first sort the vector
    std::sort(nums.begin(), nums.end());
    std::vector<int> track;
    backtrack(nums, track, 0);
    return res;
  }

  void backtrack(vector<int>& nums, vector<int>& track, int start) {
    res.push_back(track);
    for (int i{start}; i < nums.size(); i++) {
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }

      track.push_back(nums[i]);
      backtrack(nums, track, i + 1);
      track.pop_back();
    }
  }
};
// @lc code=end
