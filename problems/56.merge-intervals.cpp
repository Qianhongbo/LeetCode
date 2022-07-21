/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::vector<std::vector<int>> res;
    std::sort(intervals.begin(), intervals.end());

    res.push_back(intervals[0]);
    for (int i{1}; i < intervals.size(); i++) {
      std::vector<int> curr = intervals[i];
      std::vector<int> last = res.back();
      if (curr[0] <= last[1]) {
        res.back()[1] = std::max(curr[1], last[1]);
      } else {
        res.push_back(curr);
      }
    }

    return res;
  }
};
// @lc code=end
