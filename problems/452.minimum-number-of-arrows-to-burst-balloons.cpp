/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int tmp{0};
  int findMinArrowShots(vector<vector<int>>& points) {
    return intervalSchedule(points);
  }

  int intervalSchedule(vector<vector<int>>& points) {
    int res{1};
    // first sort the vector with the second element
    std::sort(points.begin(), points.end(), [](const vector<int>& A, const vector<int>& B) {
      return A[1] < B[1];
    });
    int end = points[0][1];
    int sz = points.size();
    for (int i{1}; i < sz; i++) {
      vector<int> curr = points[i];
      if (end < curr[0]) {
        res++;
        end = curr[1];
      }
    }

    return res;
  }
};
// @lc code=end
