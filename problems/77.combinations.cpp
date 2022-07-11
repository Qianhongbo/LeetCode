/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<std::vector<int>> res;
  vector<vector<int>> combine(int n, int k) {
    std::vector<int> track;
    backtrack(n, k, 1, track);
    return res;
  }

  void backtrack(int n, int k, int start, std::vector<int>& track) {
    if (k == track.size()) {
      res.push_back(track);
      return;
    }

    for (int i{start}; i <= n; i++) {
      track.push_back(i);
      backtrack(n, k, i + 1, track);
      track.pop_back();
    }
  }
};
// @lc code=end
