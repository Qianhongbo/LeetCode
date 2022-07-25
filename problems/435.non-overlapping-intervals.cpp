/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    return intervals.size() - intervalSchedule(intervals);
  }

  int intervalSchedule(vector<vector<int>>& intervals) {
    int res{1}; // we at least find one interval so this should be one
    std::sort(
        intervals.begin(), intervals.end(), [](const vector<int> & A, const vector<int> & B) {
          return A[1] < B[1];
        });

    int end = intervals[0][1];
    for (int i{1}; i < intervals.size(); i++) {
      std::vector<int> curr = intervals[i];
      // ! important
      if (end <= curr[0]) {
        // find next start
        res++;
        end = curr[1];
      }
    }

    return res;
  }
};
// @lc code=end
