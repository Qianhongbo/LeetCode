/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[left] <= nums[mid]) {
        // left side is sorted
        if (nums[left] <= target && target <= nums[mid]) {
          if (nums[mid] == target) {
            return mid;
          }

          right = mid - 1;
        } else {
          // target not in left side
          left = mid + 1;
        }
      } else {
        // right side is sorted
        if (nums[mid] <= target && target <= nums[right]) {
          if (nums[mid] == target) {
            return mid;
          }

          left = mid + 1;
        } else {
          // target not in left side
          right = mid - 1;
        }
      }
    }

    return -1;
  }
};
// @lc code=end
