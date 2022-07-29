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

    int getLeftBound(const vector<int>& nums, int target) {
      int left = 0, right = nums.size();

      while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
          right = mid;
        } else if (nums[mid] < target) {
          left = mid + 1;
        } else if (nums[mid] > target) {
          right = mid;
        }
      }

      if (left == nums.size()) return -1;
      return nums[left] == target ? left : -1;
    }

    int getRightBound(const vector<int>& nums, int target) {
      int left = 0, right = nums.size();

      while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
          left = mid + 1;
        } else if (nums[mid] < target) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      if (left - 1 < 0) return -1;
      return nums[left - 1] == target ? left - 1 : -1;
    }

};
// @lc code=end

