/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> res;

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // base case 
    if (0 == candidates.size()) {
      return res;
    }
    std::vector<int> track;
    int sum{0};
    backtrack(candidates, target, track, 0, sum);
    return res;
  }

  void backtrack(vector<int>& candidates, int& target, vector<int>& track, int start, int& sum) {
    if (sum == target) {
      res.push_back(track);
      return;
    }

    if (sum > target) {
      return;
    }

    for (int i{start}; i < candidates.size(); i++) {
      track.push_back( candidates[i]);
      sum += candidates[i];

      backtrack(candidates, target, track, i, sum);

      track.pop_back();
      sum -= candidates[i];
    }
  }
};
// @lc code=end
