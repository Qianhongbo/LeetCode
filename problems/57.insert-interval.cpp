/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    std::vector<std::vector<int>> res;

    int sz = intervals.size();

    int idx{0};
    // insert intervals before new interval
    while (idx < sz && intervals[idx][0] < newInterval[0]) {
      res.push_back(intervals[idx++]);
    }

    // [1 , 3]   newInterval [2, 5]
    if (res.size() && newInterval[0] <= res.back()[1]) {
      res.back()[1] = std::max(res.back()[1], newInterval[1]);
    } else {
      res.push_back(newInterval);
    }

    while (idx < sz) {
      if (intervals[idx][0] <= res.back()[1]) {
        res.back()[1] = std::max(res.back()[1], intervals[idx++][1]);
      } else {
        res.push_back(intervals[idx++]);
      }
    }

    return res;
  }
};
// @lc code=end
