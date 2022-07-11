/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      int theIndex = left + (right - left) / 2;
      int mid = nums[theIndex];

      if (mid > target) {
        right = theIndex - 1;
      } else if (mid < target) {
        left = theIndex + 1;
      } else {
        return theIndex;
      }
    }

    return -1;
  }
};
// @lc code=end
