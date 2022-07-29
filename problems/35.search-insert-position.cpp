/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        right = mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};
// @lc code=end
