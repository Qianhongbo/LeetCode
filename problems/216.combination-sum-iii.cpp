/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> res;
  vector<vector<int>> combinationSum3(int k, int n) {
    std::vector<int> track;
    int sum{0};
    backtrack(k, n, track, 1, sum);
    return res;
  }

  void backtrack(int k, int n, std::vector<int>& track, int start, int& sum) {
    if (sum == n && track.size() == k) {
      res.push_back(track);
      return;
    }

    if (sum > n || track.size() >= k) {
      return;
    }

    for (int i{start}; i <= 9; i++) {
      track.push_back(i);
      sum += i;
      backtrack(k, n, track, i + 1, sum);
      track.pop_back();
      sum -= i;
    }
  }
};
// @lc code=end
