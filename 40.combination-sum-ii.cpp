/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> res;
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    if (0 == candidates.size()) {
      return res;
    }
    // first sort the vector
    std::sort(candidates.begin(), candidates.end());

    std::vector<int> track;
    int sum{0};
    backtrack(candidates, target, 0, track, sum);
    return res;
  }

  void backtrack(vector<int>& candidates, int target, int start, vector<int>& track, int& sum) {
    if (sum == target) {
      res.push_back(track);
      return;
    }

    if (sum > target) {
      return;
    }

    for (int i{start}; i < candidates.size(); i++) {
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue;
      }

      track.push_back(candidates[i]);
      sum += candidates[i];
      backtrack(candidates, target, i + 1, track, sum);
      track.pop_back();
      sum -= candidates[i];
    }
  }
};
// @lc code=end
