/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    vector<bool> used(nums.size(), false);

    backtracking(nums, ans, current, used);

    return ans;
  }

  void backtracking(vector<int>& nums, vector<vector<int>>& ans, vector<int>& track, std::vector<bool>& used) {
    // if we have arrived the lead, just push back the result
    if (track.size() == nums.size()) {
      ans.push_back(track);
      return;
    }
    // 
    for (int i{0}; i < nums.size(); i++) {
      // if the number we have used it, just skip it
      if (used[i]) {
        continue;
      }
      // choose
      track.push_back(nums[i]);
      used[i] = true;
      // go to next layer
      backtracking(nums, ans, track, used);
      // revocation the choice
      track.pop_back();
      used[i] = false;
    }
  }
};
// @lc code=end
