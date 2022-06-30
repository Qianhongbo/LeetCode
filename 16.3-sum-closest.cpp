/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() < 3) {
      return 0;
    }

    std::sort(nums.begin(), nums.end());

    int theSize = nums.size();
    int res{0};
    int temp = std::numeric_limits<int>::max();
    for (int i{0}; i < theSize - 2; i++) {
      int left = i + 1;
      int right = theSize - 1;
      while (left < right) {
        int theSum = nums[i] + nums[left] + nums[right];

        if (std::abs(target - theSum) < temp) {
          temp = std::abs(target - theSum);
          res = theSum;
        }

        if (theSum < target) {
          left++;
        } else {
          right--;
        }
      }
    }
    return res;
  }
};
// @lc code=end
