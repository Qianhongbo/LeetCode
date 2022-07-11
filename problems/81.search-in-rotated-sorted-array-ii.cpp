/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      while (left <= right && left + 1 < nums.size() && nums[left] == nums[left + 1]) {
        left++;
      }

      while (left <= right && right - 1 > 0 && nums[right] == nums[right - 1]) {
        right--;
      }

      int mid = left + (right - left) / 2;

      if (nums[left] <= nums[mid]) {
        // left part is sorted
        if (nums[left] <= target && target <= nums[mid]) {
          // target is in left part
          if (target == nums[mid]) {
            return true;
          }
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        // right part is sorted
        if (nums[mid] <= target && target <= nums[right]) {
          // target is in the right part
          if (target == nums[mid]) {
            return true;
          }
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return false;
  }
};
// @lc code=end
