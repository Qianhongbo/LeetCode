/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int findMin(vector<int>& nums) {
    // ! important
    if (nums.size() == 1) {
      return nums[0];
    }

    int left = 0, right = nums.size() - 1;

    // ! important
    if (nums[left] < nums[right]) {
      return nums[0];
    }

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
      }

      if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
        return nums[mid];
      }

      if (nums[left] < nums[mid]) {
        // left part is sorted
        left = mid + 1;
      } else {
        // right part is sorted
        right = mid - 1;
      }
    }

    return -1;
  }
};
// @lc code=end
