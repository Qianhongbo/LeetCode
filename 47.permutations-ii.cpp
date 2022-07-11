/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> res;
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    // first sort the vector
    std::sort(nums.begin(), nums.end());

    std::vector<int> track;
    vector<bool> used(nums.size(), false);

    backtrack(nums, track, used);
    return res;
  }

  void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used) {
    if (track.size() == nums.size()) {
      res.push_back(track);
      return;
    }

    for (int i{0}; i < nums.size(); i++) {
      if (used[i]) {
        continue;
      }

      // ! the third condition is very important
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
        continue;
      }

      track.push_back(nums[i]);
      used[i] = true;
      backtrack(nums, track, used);
      track.pop_back();
      used[i] = false;
    }
  }
};
// @lc code=end
