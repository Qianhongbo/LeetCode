/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    std::vector<std::vector<int>> res{};
    // base case
    if (0 == firstList.size() || 0 == secondList.size()) {
      return res;
    }

    int i{0}, j{0};

    while (i < firstList.size() && j < secondList.size()) {
      int a1{firstList[i][0]}, a2{firstList[i][1]};
      int b1{secondList[j][0]}, b2{secondList[j][1]};

      // ! important
      if (a1 <= b2 && b1 <= a2) {
        // we have intersection
        res.push_back({std::max(a1, b1), std::min(a2, b2)});
      }

      if (b2 < a2) {
        j++;
      } else {
        i++;
      }
    }

    return res;
  }
};
// @lc code=end
