/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int theSize = height.size();
    int left = 0;
    int right = theSize - 1;
    int res = 0;
    while (left < right) {
      int theMin = std::min(height[left], height[right]);
      int temp = theMin * (right - left);
      res = std::max(res, temp);
      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return res;
  }
};
// @lc code=end
