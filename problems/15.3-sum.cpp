/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int theSize = nums.size();
    if (theSize < 3) {
      return {};
    }

    // sort the vector first
    std::sort(nums.begin(), nums.end());
    // use two pointer idea to solve this problem
    std::vector<std::vector<int>> res;
    for (int i{0}; i < theSize - 2; i++) {
      // ! This step is very important
      if (i != 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int theTarget = -nums[i];
      int left = i + 1;
      int right = theSize - 1;

      while (left < right) {
        int theLeftNum = nums[left];
        int theRightNum = nums[right];
        if (theTarget == theLeftNum + theRightNum) {
          res.push_back({nums[i], theLeftNum, theRightNum});
          // ! This step is very important
          while(left + 1 < right && nums[left] == nums[left + 1]) left++;
          while(right - 1 > left && nums[right - 1] == nums[right]) right--;
          left++;
          right--;
        } else if (theTarget > theLeftNum + theRightNum) {
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
