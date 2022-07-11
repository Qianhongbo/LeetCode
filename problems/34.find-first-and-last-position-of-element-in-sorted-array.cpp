/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

#include <vector>
using namespace std;

//  1 2 3 4 4 4 4 5
//        m l   

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      if (nums.size() == 0) return {-1, -1};

      int theLeft = getLeftBound(nums, target);
      int theRight = getRightBound(nums, target);

      return {theLeft, theRight};
    }

    int getRightBound(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > target) {
          right = mid - 1;
        } else if (nums[mid] < target) {
          left = mid + 1;
        } else {
          // find the target number 
          // but still need to find  the start and end
          if (mid == right || nums[mid + 1] != target) {
            return mid;
          }
          left = mid + 1;
        }
      }
      return -1;
    }

    int getLeftBound(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1;

      while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > target) {
          right = mid - 1;
        } else if (nums[mid] < target) {
          left = mid + 1;
        } else {
          if (mid == left || nums[mid - 1] != target) {
            return mid;
          }
          right = mid - 1;
        }
      }
      return -1;
    }
};
// @lc code=end

