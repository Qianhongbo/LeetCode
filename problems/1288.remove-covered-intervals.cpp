/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int res{0};

    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      }

      return a[0] < b[0];
    });

    int left = intervals[0][0], right = intervals[0][1];
    int sz = intervals.size();
    for (int i{1}; i < sz; i++) {
      std::vector<int> curr = intervals[i];

      // three conditions
      // 1. cover
      if (curr[1] <= right) {
        res++;
      }

      // 2. overlap
      if (curr[0] <= right && right <= curr[1]) {
        right = curr[1];
      } 
      
      // 3. not overlap
      if (curr[0] > right) {
        left = curr[0];
        right = curr[1];
      }
    }

    return intervals.size() - res;
  }
};
// @lc code=end
